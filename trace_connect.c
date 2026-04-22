/* eBPF 설계
   connect() 호출 감지 및 사용자 공간으로 이벤트 전송 */

#include <uapi/linux/ptrace.h>
BPF_PERF_OUTPUT(events);

struct data_t {
    u32 pid;    // 부호없는 32byte 자료형 pid(프로세스 id) 구조체 멤버 
    u64 ts;     // 부호없는 64byte 자료형 ts(PID별 session) 구조체 멤버
};

int trace_connect(struct pt_regs *ctx) {
    struct data_t evt = {};
    evt.pid = bpf_get_current_pid_tgid();
    evt.ts  = bpf_ktime_get_ns();
    events.perf_submit(ctx, &evt, sizeof(evt));
    return 0;
}

// 커널 이벤트 캡처 (eBPF Instrumentation): eBPF 프로그램을 이용해 
// 커널 수준에서 봇 관련 이벤트(예: 네트워크 연결, 인증 호출 등)를 실시간으로 가로챔. 
// 예를 들어, `tracepoint:syscalls:sys_enter_connect`나 `kprobe/tcp_connect`를 
// 걸어 봇 서버로의 연결 시도를 모니터링하고, `BPF_PERF_OUTPUT`을 통해 사용자 공간으로 이벤트를 전송함. 
// 커널 내부의 `BPF_HASH` 맵을 사용하여 PID별 세션 정보를 저장하거나, 인증 시도 횟수를 누적할 수 있음.