#include <thread>
#include <vector>
#include <cmath>

void cpumax() {
    while (true) {
        double x = 0.0001;
        for (int i = 0; i < 1000000; ++i) {
            x += std::sin(x) * std::cos(x);
        }
    }
}

int main() {
    unsigned int cores = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    for (unsigned int i = 0; i < cores; ++i)
        threads.emplace_back(cpumax);

    for (auto& t : threads)
        t.join();
}