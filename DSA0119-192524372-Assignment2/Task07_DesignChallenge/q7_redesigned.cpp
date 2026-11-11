#include <iostream>
using namespace std;

// Redesigned fixed-capacity circular buffer: overwrite oldest in O(1).
class CircularHistory {
    int data[10]{};
    int count = 0;
    int next = 0;
public:
    void add(int value) {
        data[next] = value;
        next = (next + 1) % 10;
        if (count < 10) ++count;
    }
    void print() const {
        int start = (count == 10) ? next : 0;
        for (int i = 0; i < count; ++i)
            cout << data[(start + i) % 10] << ' ';
        cout << '\n';
    }
};
int main() {
    CircularHistory h;
    for (int i = 1; i <= 15; ++i) h.add(i);
    h.print();
}
