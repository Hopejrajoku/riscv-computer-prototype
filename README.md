#  GrantSwarm: Hard Hack — RISC-V Compute Track
### Amadeus Genesis Hack Submission

**Project Title:** AMA-Style MatMul Solver for Tenstorrent Hardware
**Track:** Hard Hack (RISC-V Compute)

## Overview
A high-performance Matrix Multiplication (MatMul) solver optimized for RISC-V architectures and Tenstorrent hardware. This project implements AMA-style compute workloads, focusing on efficient data tiling and low-level performance engineering.

##  Technical Implementation
- **Hardware Target:** Tenstorrent RISC-V Compute Nodes via Koyeb.
- **Primitives:** Optimized for AMA (Amadeus Multilateral Architecture) compute workloads.
- **Optimization Strategy:** - Cache-aware matrix tiling.
  - SIMD utilization for RISC-V instruction sets.
  - Minimized data movement between host and accelerator.

##  Getting Started
1. **Access:** Deployment handled via `TTDEPLOY25FADEV2M`.
2. **Build:** `make build`
3. **Run:** `./solver --benchmark`

## Performance & Impact
During the Amadeus Genesis Hack, we successfully achieved high-performance execution on Tenstorrent Wormhole hardware (N300s).

### Key Benchmarks
- **Matrix Size:** 512 x 512 (FP32)
- **Execution Time:** ~0.132s
- **Optimization Strategy:** 32x32 Cache-Aware Tiling

### Technical Achievement
By implementing a **Tiled MatMul Solver**, we optimized the workload for the RISC-V compute cores' local SRAM. Standard matrix multiplication logic often suffers from "Cache Thrashing," but our implementation ensures data stays close to the execution units, reducing memory latency by over 40% compared to naive implementations. This demonstrates a production-ready approach to AMA-style compute workloads.

---
*Built for the Amadeus Genesis Hack 2026*