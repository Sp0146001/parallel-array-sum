#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <numeric>

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

void sumRange(const data_t& data, size_t start, size_t end, value_t& result) {
    value_t local_sum = 0;
    for (size_t i = start; i < end; ++i) {
        local_sum += data[i];
    }
    result = local_sum;
}

value_t parallelSum(const data_t& data, size_t num_threads) {
    size_t size = data.size();
    if (num_threads == 0) num_threads = 1;
    if (num_threads > size) num_threads = size;

    std::vector<std::thread> threads;
    std::vector<value_t> partial_sums(num_threads, 0);
    size_t chunk_size = size / num_threads;

    for (size_t i = 0; i < num_threads; ++i) {
        size_t start = i * chunk_size;
        size_t end = (i == num_threads - 1) ? size : (i + 1) * chunk_size;
        threads.emplace_back(sumRange, std::cref(data), start, end, std::ref(partial_sums[i]));
    }

    for (auto& t : threads) {
        t.join();
    }

    value_t total_sum = 0;
    for (size_t i = 0; i < num_threads; ++i) {
        total_sum += partial_sums[i];
    }
    return total_sum;
}
