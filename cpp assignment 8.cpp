#include <iostream>
using namespace std;

class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amount) {
        try {
            if (amount <= 0)
                throw amount;

            balance += amount;
            cout << "Amount deposited successfully!" << endl;
        }
        catch (double x) {
            cout << "Exception: Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        try {
            if (amount <= 0)
                throw amount;

            if (amount > balance)
                throw "Insufficient balance!";

            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        }
        catch (double x) {
            cout << "Exception: Invalid withdrawal amount!" << endl;
        }
        catch (const char* msg) {
            cout << "Exception: " << msg << endl;
        }
    }

    void displayBalance() {
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount account(5000);
    int choice;
    double amount;

    do {
        cout << "\n--- Banking Management System ---" << endl;
        cout << "1. Deposit Amount" << endl;
        cout << "2. Withdraw Amount" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.displayBalance();
                break;

            case 4:
                cout << "Exiting Banking System..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
