# TCP 연결 이벤트를 추적하는 BCC(BPF Compiler Collection)

from bcc import BPF
from collections import defaultdict # 인증/세션 기반 이상 탐지 자료구조(collections)

# eBPF C 코드(trace_connect.c)를 Python bcc.py로 로드
bpf_text = open("../ebpf/trace_connect.c").read()
b = BPF(text=bpf_text)
b.attach_kprobe(event="__x64_sys_connect", fn_name="trace_connect") # sys_enter_connect <- deprecated  

# sessions = {}    # 기존 세션 저장 리스트 {pid: [timestamp_list]} ->
sessions = defaultdict(list)    # Hash Map (key: pid, value: timestamp list)

def handle_event(cpu, data, size):
    evt = b["events"].event(data)
    pid = evt.pid; ts = evt.ts / 1e9  # ns -> s
    sessions.setdefault(pid, []).append(ts)
    
#     window = [t for t in sessions[pid] if ts - t < 10]
#     if len(window) >= 5:
#         print(f"!repeated connection detection: PID={pid}, Count={len(window)}")

    WINDOW = 10  # 10초 내 5회 시도 시 경고
    sessions[pid] = [t for t in sessions[pid] if ts - t < WINDOW]
    if len(sessions[pid]) > 5:
        print(f"!! Detect duplicate connections {pid}") # Sliding Windows 확장(자료구조 초기화)
b["events"].open_perf_buffer(handle_event) 

while True:
    b.kprobe_poll()

# 사용자 공간 탐지 (DSA 기반 분석): BCC/PyBPF 등을 이용해 커널에서 전송된 이벤트를
# 수신함. 사용자 공간에서는 해시맵(Hash Map)으로 세션 상태(예: PID별 인증 실패
# 횟수)를 추적하고, 슬라이딩 윈도우로 단기간 반복 시도를 검출함. 예를 들어, 한 세션
# 에서 10초 이내 5회 이상 연결 시도가 발생하면 경고를 발생시킬 수 있다. 그래프(Graph) 
# 자료구조를 도입하여 클라이언트-서버-API 흐름을 노드/간선으로 모델링하고, 비정상적인 경로(bypass, lateral movement)
# 를 탐지할 수도 있다. 또한 **상태 머신(State Machine)을 통해 “인증 전/후” 상태를 
# 정의해 인증 없이 주요 기능 접근을 차단하고, 단순 룰 엔진(rule engine)으로 요청 종류에 
# 따른 허용·차단 로직을 구현할 수 있다.

# 연계 설계: eBPF는 저오버헤드로 실시간 데이터 수집을 담당하고, 
# DSA(자료구조·알고리즘)는 수집된 데이터를 효율적으로 분석함. 예를 들어, 
# eBPF로 얻은 커널 이벤트를 메모리 내 해시맵과 슬라이딩 윈도우로 빠르게 처리함으로써 
# 봇의 이상 징후(비정상 인증, 의심 네트워크 흐름)를 초저지연으로 탐지할 수 있음. 
# 이 결합을 통해 커널/네트워크 레벨부터 애플리케이션 로직까지 아우르는 종합적인 보안 모니터링 
# 시스템을 구현할 수 있다.
