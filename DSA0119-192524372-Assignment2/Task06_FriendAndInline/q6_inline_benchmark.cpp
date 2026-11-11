#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

inline int addInline(int a, int b) { return a + b; }
int addNormal(int a, int b) { return a + b; }

int main() {
    constexpr long long N = 10000000;
    volatile long long sink = 0;

    auto start1 = steady_clock::now();
    for (long long i = 0; i < N; ++i) sink += addInline(int(i % 100), 2);
    auto end1 = steady_clock::now();

    auto start2 = steady_clock::now();
    for (long long i = 0; i < N; ++i) sink += addNormal(int(i % 100), 2);
    auto end2 = steady_clock::now();

    cout << "Inline ms: "
         << duration<double, milli>(end1 - start1).count() << '\n';
    cout << "Normal ms: "
         << duration<double, milli>(end2 - start2).count() << '\n';
    cout << "Prevent optimisation: " << sink << '\n';
}
