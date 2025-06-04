// Encapsulation is the process of bundling data and the methods that operate on that data 
// into a single unit (class), while restricting direct access to some of the object’s components.


#include<iostream>

using namespace std;


class BankAccount {

    // Private data members - cannot be accessed directly from outside
    private:
    int accountNumber;
    double balance;

    // Public methods - provide controlled access to private data
    public:

    // Setter for account number
    void setAccountNumber(int accNo) {
        if(accNo > 0) {
            accountNumber = accNo;
        } else {
            cout << "Invalid Account Number!!!" << endl;
        }
    }

    // Getter for account number
    int getAccountNumber() {
        return accountNumber;
    }

    // Setter for balance
    void setBalance(double amount) {
        if(amount >= 0) {
            balance = amount;
        } else {
            cout << "Balance cannot be negative!" << endl;
        }
    }

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Method to display account details
    void displayAccount() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount account;

    account.setAccountNumber(123456);
    account.setBalance(1000.50);

    //displaying account information
    account.displayAccount();

    // Direct access like this would be an error:
    // account.balance = -100; (not allowed)
    // account.accountNumber = 0; (not allowed)

    return 0;
}
