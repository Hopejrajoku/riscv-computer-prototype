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

---
*Built for the Amadeus Genesis Hack 2026*