/* eBPF 설계
   실시간 connect() 호출 감지 및 사용자 공간으로 이벤트 전송 */

#include <uapi/linux/ptrace.h> // 레지스터 정보를 담고 있는 pt_regs 구조체를 사용하기 위해 커널 헤더 가져옴. 
BPF_PERF_OUTPUT(events); // 커널에서 수집한 데이터를 사용자 공간으로 쏘아 올린 Perf Ring Buffer의 이름을 events로 지정하여 생성

/* 구조체 정의(Data Design) */
struct data_t { // 추적할 정보를 담을 구조체 생성
    u32 pid;    // pid(프로세스 id) 멤버(부호없는 8byte) 선언
    u64 ts;     // ts(Time Stamp) 선언 -> 이벤트가 발생한 시점의 시간
};

/* 추적 함수(Trace_connect) */
int trace_connect(struct pt_regs *ctx) {
    struct data_t evt = {};                 // 데이터 초기화
    evt.pid = bpf_get_current_pid_tgid();   // PID 획득, 호출 함수는 상위 32비트에 TGID(프로세스 ID), 하위 32비트에 PID(스레드 ID)를 반환하는데, 이를 evt.pid에 대입하여 현재 프로세스 ID만 추출
    evt.ts  = bpf_ktime_get_ns();           // 시간 기록, 호출 함수를 통해 부팅 이후 흐른 시간을 나노초(ns) 단위로 가져와 저장
    events.perf_submit(ctx, &evt, sizeof(evt)); // 해당 함수를 호출하여 앞서 정의한 events 통로를 통해 수집된 데이터를 사용자 공간의 모니터링 프로그램을 즉시 전송
    return 0;   // 커널에 제어권을 돌려줌 (시스템 호출 후 사용자 모드 복귀)
}

// 커널 이벤트 캡처 (eBPF Instrumentation): eBPF 프로그램을 이용해 
// 커널 수준에서 봇 관련 이벤트(예: 네트워크 연결, 인증 호출 등)를 실시간으로 가로챔. 
// 예를 들어, `tracepoint:syscalls:sys_enter_connect`나 `kprobe/tcp_connect`를 
// 걸어 봇 서버로의 연결 시도를 모니터링하고, `BPF_PERF_OUTPUT`을 통해 사용자 공간으로 이벤트를 전송함. 
// 커널 내부의 `BPF_HASH` 맵을 사용하여 PID별 세션 정보를 저장하거나, 인증 시도 횟수를 누적할 수 있음.