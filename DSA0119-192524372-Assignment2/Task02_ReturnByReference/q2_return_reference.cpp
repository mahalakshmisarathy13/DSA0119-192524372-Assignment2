#include <iostream>
#include <algorithm>
using namespace std;

int& highestMark(int marks[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[index]) index = i;
    return marks[index];
}

// Deliberately unsafe demonstration: compile may warn; NEVER call this function.
// The returned reference dangles after the local variable's lifetime ends.
int& dangerousLocalReference() {
    int local = 75;
    return local; // undefined behaviour if the returned reference is used
}

int highestIndex(const int marks[], int size) {
    int index = 0;
    for (int i = 1; i < size; ++i)
        if (marks[i] > marks[index]) index = i;
    return index;
}
int* highestPointer(int marks[], int size) {
    return &marks[highestIndex(marks, size)];
}

int main() {
    int marks[] = {78, 91, 84, 88, 91};
    int size = sizeof(marks) / sizeof(marks[0]);
    cout << "Highest before moderation: " << highestMark(marks, size) << '\n';
    highestMark(marks, size) += 2;
    cout << "Highest after moderation: " << highestMark(marks, size) << '\n';

    int index = highestIndex(marks, size);
    cout << "Index of highest mark: " << index << '\n';
    int* ptr = highestPointer(marks, size);
    cout << "Highest using pointer: " << *ptr << '\n';
    return 0;
}
