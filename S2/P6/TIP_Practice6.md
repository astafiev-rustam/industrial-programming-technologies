# Пример 1
```C++
#include <iostream>
using namespace std;

int divide(int a, int b) {
    if (b == 0) {
        throw "Division by zero!";
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        cout << "Result: " << result << endl;
    } catch (const char* error) {
        cout << "Error: " << error << endl;
    }
    return 0;
}
```
# Пример 2
```C++
#include <iostream>
#include <exception>
using namespace std;

class DivisionByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "Division by zero exception!";
    }
};

int divide(int a, int b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        cout << "Result: " << result << endl;
    } catch (const DivisionByZeroException& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
```
# Пример 3
```C++
#include <iostream>
#include <exception>
using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw "Insufficient funds!";
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(100);
    try {
        account.withdraw(150);
    } catch (const char* error) {
        cout << "Error: " << error << endl;
    }
    cout << "Balance: " << account.getBalance() << endl;
    return 0;
}
```
