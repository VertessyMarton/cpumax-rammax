#include <vector>
#include <cstdlib>
#include <cstring>

int main() {
    std::vector<void*> a;
    while (true) {
        void* b = std::malloc(10 * 1024 * 1024);
        if (b) {
            std::memset(b, 0, 10 * 1024 * 1024);
            a.push_back(b);
        }
        
    }
    return 0;
}
