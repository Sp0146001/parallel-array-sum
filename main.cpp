#include <iostream>
#include <vector>
#include <chrono>

using data_t = std::vector<unsigned long long>;
using value_t = data_t::value_type;

class Clicker {
public:
    Clicker() : start_(std::chrono::steady_clock::now()) {}
    double millisec() const {
        auto t = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(t - start_).count();
    }
private:
    std::chrono::time_point<std::chrono::steady_clock> start_;
};

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    
    size_t num_threads = std::stoul(argv[1]);
    constexpr size_t ARRAY_SIZE = 1'000'000'000ULL;
    data_t values(ARRAY_SIZE, 1);
    
    return 0;
}
