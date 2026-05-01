/* eBPF Design
 *
 * We are not building a full network monitor.
 * We are extracting just enough signal from connect() to detect abnormal behavior early.
 *
 * Kernel space collects facts. User space decides meaning.
 */

#include <uapi/linux/ptrace.h>  
// We depend on pt_regs because kprobes expose raw register state.
// This is a low-level contract—fragile across architectures, but powerful.


BPF_PERF_OUTPUT(events);  
// This is our only exit path to user space.
// Keep it simple: push raw events, avoid complex logic in kernel.
// If you over-engineer here, debugging becomes painful fast.


/* Data Design
 *
 * Minimalism is intentional.
 * Every extra field increases overhead and reduces portability.
 */
struct data_t {
    u32 pid;   // We only keep what we can act on quickly.
               // PID is enough for coarse-grained anomaly detection.

    u64 ts;    // Time is context.
               // Without time, behavior is just noise.
};


/* Trace Function
 *
 * This runs in kernel context—treat it as a constrained environment:
 * - no loops (or very limited)
 * - no heavy memory usage
 * - no assumptions about safety
 */
int trace_connect(struct pt_regs *ctx) {

    struct data_t evt = {};  
    // Always initialize.
    // Kernel bugs are not forgiving.

    evt.pid = bpf_get_current_pid_tgid();  
    // This returns both TGID and PID.
    // We intentionally accept ambiguity here—precision can be handled later in user space.

    evt.ts  = bpf_ktime_get_ns();  
    // Use monotonic time.
    // Wall-clock time introduces drift and inconsistency.

    events.perf_submit(ctx, &evt, sizeof(evt));  
    // Ship the event immediately.
    // Do not batch here—latency matters more than throughput at this stage.

    return 0;  
    // Always return cleanly.
    // You are a guest in the kernel—leave no side effects.
}


/* Instrumentation Strategy
 *
 * Hook selection is a design decision:
 *
 * - tracepoint:syscalls:sys_enter_connect → stable, lower risk
 * - kprobe/tcp_connect                  → deeper visibility, more fragile
 *
 * Choose stability first, depth later.
 *
 * We are not trying to see everything.
 * We are trying to see enough to act.
 */


/* State Handling (Optional)
 *
 * Kernel maps (e.g., BPF_HASH) can store state,
 * but this is a trade-off:
 *
 * - Pros: fast, in-kernel correlation
 * - Cons: harder to debug, limited complexity
 *
 * Default rule:
 * Keep state in user space unless latency forces you otherwise.
 */


/* Design Philosophy
 *
 * eBPF is for observation, not intelligence.
 *
 * Let the kernel:
 *   - capture events
 *   - timestamp them
 *
 * Let user space:
 *   - correlate events
 *   - detect anomalies
 *   - make decisions
 *
 * Mixing these concerns leads to brittle systems.
 */


/* Scaling Considerations
 *
 * This design will break under:
 * - extremely high connection rates
 * - slow user-space consumers
 *
 * When that happens:
 * - switch to ring buffer (BPF_RINGBUF_OUTPUT)
 * - introduce sampling
 * - or move partial aggregation into kernel maps
 *
 * Do not optimize before you see dropped events.
 */


/* What This Detects Well
 *
 * - burst connection attempts (possible scanning / DDoS precursors)
 * - runaway processes making repeated connections
 *
 * What it does NOT detect:
 * - low-and-slow attacks
 * - protocol-level anomalies
 *
 * That’s fine.
 * This is an early-warning system, not a full IDS.
 */