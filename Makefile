CXX = g++
CXXFLAGS = -O2 -pthread -std=c++17

all: parallel_sum

parallel_sum: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o parallel_sum

clean:
	rm -f parallel_sum

.PHONY: all clean
