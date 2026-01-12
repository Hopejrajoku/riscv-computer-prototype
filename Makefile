# Compiler settings for RISC-V
CXX = g++
CXXFLAGS = -O3 -std=c++17 -Wall

# Target binary name
TARGET = solver

# Build rule
all:
	$(CXX) $(CXXFLAGS) solver.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)