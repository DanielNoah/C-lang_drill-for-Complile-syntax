# We are not trying to capture *all* TCP connections.
# We are trying to capture *enough signal* to detect abnormal behavior early.
# Precision can come later—latency cannot.

from bcc import BPF
from collections import defaultdict  # Choose simple structures first; optimize only if needed.

# Load eBPF program.
# Treat this as a contract: kernel collects raw facts, user space interprets meaning.
bpf_text = open("../ebpf/trace_connect.c").read()

# Compile and load into kernel space.
# If this step fails, nothing else matters—fail fast.
b = BPF(text=bpf_text)

# Hook into connect syscall.
# This is a strategic choice:
# - High signal for network anomalies
# - Low enough frequency to avoid overwhelming the pipeline
b.attach_kprobe(event="__ARM64_sys_connect", fn_name="trace_connect")

# Session state: PID → timestamps
# We deliberately keep it simple (list), not optimal.
# Premature optimization here would hide logic clarity.
sessions = defaultdict(list)


def handle_event(cpu, data, size):
    # Translate raw kernel event into usable data.
    # Keep transformation minimal—this is not the place for heavy logic.
    evt = b["events"].event(data)

    pid = evt.pid
    ts = evt.ts / 1e9  # Convert early to human-friendly units

    # Record activity.
    # We accept temporary redundancy for clarity.
    sessions[pid].append(ts)

    WINDOW = 10  # seconds

    # Sliding window:
    # Instead of tracking absolute counts, we care about *recent behavior*.
    # Systems fail in bursts, not averages.
    sessions[pid] = [t for t in sessions[pid] if ts - t < WINDOW]

    # Detection rule:
    # Simple thresholds beat complex models in early-stage systems.
    # Make it obvious, then make it smarter later.
    if len(sessions[pid]) > 5:
        print(f"[ALERT] Suspicious activity from PID {pid}")
        # We don't reset immediately—bursty attackers should remain visible.


# Connect kernel → user space pipeline.
# If you don't consume events fast enough, you will lose them.
# Monitoring systems fail silently—assume backpressure exists.
b["events"].open_perf_buffer(handle_event)


# Main loop:
# Polling is explicit and predictable.
# Event-driven models are elegant, but harder to debug at this stage.
while True:
    b.kprobe_poll()


# ---- Design Notes ----

# eBPF is used for *observation*, not decision-making.
# Keep kernel logic minimal—bugs in kernel space are expensive.

# User space owns intelligence:
# - Hash maps → fast state lookup
# - Sliding windows → temporal context
# - Rules → explicit, debuggable logic

# Graph models can be introduced later:
# - Nodes: processes, endpoints
# - Edges: connections
# Useful for detecting lateral movement, not just frequency anomalies.

# State machines are optional—but powerful:
# Define "before authentication" vs "after authentication"
# and enforce transitions explicitly.

# Rule engines should stay simple:
# Complex rules become invisible rules.

# This system is not trying to be perfect.
# It is trying to be *early*.

# If you can detect:
# - sudden bursts (possible DDoS / scanning)
# - abnormal retry loops (bug or exploit)
# - unusual connection patterns
# you already have operational value.

# eBPF + simple data structures is a force multiplier:
# low overhead in kernel, fast reasoning in user space.

# Optimize only after:
# - you see dropped events
# - latency becomes visible
# - memory growth becomes measurable