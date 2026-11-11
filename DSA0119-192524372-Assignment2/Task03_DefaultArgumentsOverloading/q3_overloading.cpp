#include <iostream>
#include <string>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

double charge(int grams) {
    return 40.0 + (grams / 1000.0) * 20.0;
}
double charge(double weightKg, bool express = false, bool insured = false) {
    double total = 40.0 + weightKg * 20.0;
    if (express) total += 30.0;
    if (insured) total += 15.0;
    return total;
}
double charge(const Parcel& p) {
    return charge(p.weightKg, p.express, p.insured);
}

int main() {
    // Predictions: int overload; double overload; double overload;
    // double overload; Parcel overload; int overload.
    cout << "charge(2): " << charge(2) << '\n';
    cout << "charge(2.0): " << charge(2.0) << '\n';
    cout << "charge(2.0f): " << charge(2.0f) << '\n';
    cout << "charge(2.5, true): " << charge(2.5, true) << '\n';
    Parcel p{3.0, false, true};
    cout << "charge(Parcel): " << charge(p) << '\n';
    cout << "charge(1500): " << charge(1500) << '\n';
    return 0;
}
