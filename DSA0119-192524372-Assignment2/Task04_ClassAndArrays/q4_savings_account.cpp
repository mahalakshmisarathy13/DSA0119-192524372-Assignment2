#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;
    double transactions[10];
    int count;
    int next; // next insertion position; oldest item is overwritten when full

    void record(double amount) {
        transactions[next] = amount;
        next = (next + 1) % 10;
        if (count < 10) ++count;
    }

public:
    SavingsAccount(const string& number, double openingBalance)
        : accountNumber(number), balance(openingBalance), count(0), next(0) {}

    void deposit(double amount) {
        if (amount <= 0) { cout << "Invalid deposit\n"; return; }
        balance += amount;
        record(amount);
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid withdrawal\n"; return;
        }
        balance -= amount;
        record(-amount);
    }

    void miniStatement() const;
    double getBalance() const { return balance; }
};

void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << "\nBalance: " << balance
         << "\nRecent transactions (oldest to newest):\n";
    int start = (count == 10) ? next : 0;
    for (int i = 0; i < count; ++i)
        cout << transactions[(start + i) % 10] << '\n';
}

int main() {
    SavingsAccount account("SB1001", 5000);
    account.deposit(1000);
    account.withdraw(500);
    for (int i = 1; i <= 10; ++i) account.deposit(i * 10);
    account.miniStatement();
    return 0;
}
