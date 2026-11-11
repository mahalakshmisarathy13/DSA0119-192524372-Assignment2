#include <iostream>
using namespace std;

// Original design: shift all existing values left when the array is full.
class ShiftHistory {
    int data[10]{};
    int count = 0;
public:
    void add(int value) {
        if (count < 10) data[count++] = value;
        else {
            for (int i = 1; i < 10; ++i) data[i - 1] = data[i];
            data[9] = value;
        }
    }
    void print() const {
        for (int i = 0; i < count; ++i) cout << data[i] << ' ';
        cout << '\n';
    }
};
int main() {
    ShiftHistory h;
    for (int i = 1; i <= 15; ++i) h.add(i);
    h.print();
}
