# TCP 연결 이벤트를 추적하는 BCC(BPF Compiler Collection) 라이브러리를 
# 사용해서 특정 시간 내 과도한 연결 요청을 잡아내는 이상 탐지(Anormaly Detection) 모니터링 프로그램

from bcc import BPF
from collections import defaultdict # 인증/세션 기반 이상 탐지 자료구조(collections)
 
# 초기화 및 컴파일
# eBPF C 코드(trace_connect.c)를 Python bcc.py로 로드

bpf_text = open("../ebpf/trace_connect.c").read() # 작성한 trace_connect.c 파일을 읽어와 BPF를 통해 커널이 이해할 수 있는 명령어로 컴파일
b = BPF(text = bpf_text) 
b.attach_kprobe(event = "__ARM64_sys_connect", fn_name="trace_connect") # sys_enter_connect <- deprecated  
# 리눅스 커널의 네트워크 연결 함수인 위의 이벤트가 발생될 때마다 C로 작성한 trace_connect 함수가 자동으로 실행되도록 설정

# sessions = {}    # 기존 세션 저장 리스트 {pid: [timestamp_list]}
sessions = defaultdict(list)    # Hash Map (key: pid, value: timestamp list)

# 데이터 수집 및 전달(Data Pipeline)
# 커널 내부 (trace_connect.c) : 시스템 콜이 발생하면 PID와 시간을 수집해 perf_submit으로 쏨
def handle_event(cpu, data, size):
    evt = b["events"].event(data)   # b.kprobe_poll() 이 루프를 돌며 대기하다가, 데이터가 들어오면 handle_event 함수 실행
    pid = evt.pid; ts = evt.ts / 1e9  # ns -> s (나노초를 현재 시간 초단위로 변환)
    sessions.setdefault(pid, []).append(ts)
    WINDOW = 10  
# 현재 시간 기준으로 10초(WINDOW)보다 더 오래된 기록은 리스트에서 제거. 즉, 리스트에는 항상 '최근 10초간의 기록'만 남음    
    sessions[pid] = [t for t in sessions[pid] if ts - t < WINDOW]
# -> 이 방식은 매 이벤트마다 리스트를 새로 만드므로, 일반적인 모니터링 상황에서는 직관적인 구현
#    (** 데이터 양이 아주 많아지면 성능에 영향을 줄 수는 있음 **)

# 10초 내 5회(임계치, threshold) 시도 시 경고하는 조건 제어문
    if len(sessions[pid]) > 5:
        print(f"[ALERT] Suspicious activity from PID {pid}") # Sliding Windows 확장(자료구조 초기화)
b["events"].open_perf_buffer(handle_event) 

while True:
    b.kprobe_poll() # 무한 루프를 통해 프로그램이 종료될 때까지 커널로부터 전달되는 이벤트를 계속 감시(Polling)

# 사용자 공간 탐지 (DSA 기반 분석): BCC/PyBPF 등을 이용해 커널에서 전송된 이벤트를
# 수신함. 사용자 공간에서는 ** 해시맵(Hash Map)으로 세션 상태(예: PID별 인증 실패
# 횟수)를 추적하고, ** 슬라이딩 윈도우로 단기간 반복 시도를 검출함. 예를 들어, 한 세션
# 에서 10초 이내 5회 이상 연결 시도가 발생하면 경고를 발생시킬 수 있다. ** 그래프(Graph) 
# 자료구조를 도입하여 클라이언트-서버-API 흐름을 노드/간선으로 모델링하고, 비정상적인 경로(bypass, lateral movement)
# 를 탐지할 수도 있다. 또한 ** 상태 머신(State Machine)을 통해 “인증 전/후” 상태를 
# 정의해 인증 없이 주요 기능 접근을 차단하고, ** 단순 룰 엔진(rule engine)으로 요청 종류에 
# 따른 허용·차단 로직을 구현할 수 있다.

# 연계 설계: eBPF는 낮은 오버헤드로 실시간 데이터 수집을 담당하고, 
# DSA(자료구조·알고리즘)는 수집된 데이터를 효율적으로 분석함. 예를 들어, 
# eBPF로 얻은 커널 이벤트를 메모리 내 해시맵과 슬라이딩 윈도우로 빠르게 처리함으로써 
# 봇의 이상 징후(비정상 인증, 의심 네트워크 흐름)를 초저지연으로 탐지할 수 있음. 
# 이 결합을 통해 커널/네트워크 레벨부터 애플리케이션 로직까지 아우르는 종합적인 보안 모니터링 
# 시스템을 구현할 수 있다. 특히, 탐지 시나리오로 Port Scanning이나 DDoS 공격의 전조 증상, 
# 혹은 특정 프로세스가 무한 루프에 빠져 네트워크 연결을 시도하는 버그 등을 잡아낼 때 유용