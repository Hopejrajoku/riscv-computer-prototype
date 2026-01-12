#include <iostream>
#include <vector>
#include <chrono>

// BLOCK_SIZE is the "Tile" size. 
// For Tenstorrent RISC-V, 32 or 64 is usually the sweet spot for SRAM.
const int BLOCK_SIZE = 32;

void tiled_matmul(int N, const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C) {
    // AMA-style Tiled Matrix Multiplication
    for (int i0 = 0; i0 < N; i0 += BLOCK_SIZE) {
        for (int j0 = 0; j0 < N; j0 += BLOCK_SIZE) {
            for (int k0 = 0; k0 < N; k0 += BLOCK_SIZE) {
                
                // Inner loops work on the "Tile"
                for (int i = i0; i < std::min(i0 + BLOCK_SIZE, N); ++i) {
                    for (int j = j0; j < std::min(j0 + BLOCK_SIZE, N); ++j) {
                        float sum = 0;
                        for (int k = k0; k < std::min(k0 + BLOCK_SIZE, N); ++k) {
                            sum += A[i * N + k] * B[k * N + j];
                        }
                        C[i * N + j] += sum;
                    }
                }

            }
        }
    }
}

int main() {
    std::vector<int> sizes = {512, 1024, 2048};
    
    for (int N : sizes) {
        std::vector<float> A(N * N, 1.0f);
        std::vector<float> B(N * N, 2.0f);
        std::vector<float> C(N * N, 0.0f);

        std::cout << "Benchmarking N=" << N << "..." << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        tiled_matmul(N, A, B, C);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Size " << N << " took " << elapsed.count() << "s" << std::endl;
    }

    std::cout << "🏁 All benchmarks complete. Entering idle state..." << std::endl;
    while(true) { sleep(1000); } // Keeps the Koyeb service "Healthy"
    return 0;
}