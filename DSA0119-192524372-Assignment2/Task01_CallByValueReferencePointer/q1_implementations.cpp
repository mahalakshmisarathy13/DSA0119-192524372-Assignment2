#include <iostream>
using namespace std;

void concessionByValue(double fee, int percent) {
    fee -= fee * percent / 100.0;
    cout << "Inside value function: " << fee << '\n';
}
void concessionByReference(double& fee, int percent) {
    fee -= fee * percent / 100.0;
}
void concessionByPointer(double* fee, int percent) {
    if (fee != nullptr) *fee -= *fee * percent / 100.0;
}

int main() {
    double valueFee = 45000, referenceFee = 45000, pointerFee = 45000;
    concessionByValue(valueFee, 10);
    concessionByReference(referenceFee, 10);
    concessionByPointer(&pointerFee, 10);
    cout << "Stored fee after value: " << valueFee << '\n';
    cout << "Stored fee after reference: " << referenceFee << '\n';
    cout << "Stored fee after pointer: " << pointerFee << '\n';
    return 0;
}
