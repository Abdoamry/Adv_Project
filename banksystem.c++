#include<iostream>
#include<string>
using namespace std;

class bank {
    string name, address, accountType;
    int balance;

public:
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
};

void bank::open_account() {
    cout << "Enter your Full name: ";
    getline(cin >> ws, name); // لتجنب مشاكل الإدخال
    cout << "Enter your address: ";
    getline(cin >> ws, address);
    cout << "What type of account you want to open? (Saving/Current): ";
    cin >> accountType;
    cout << "Enter initial deposit amount: ";
    cin >> balance;
    cout << "Your account is created successfully!\n";
}

void bank::deposit_money() {
    int deposit;
    cout << "Enter amount to deposit: ";
    cin >> deposit;
    balance += deposit;
    cout << "Amount deposited successfully! Current balance: " << balance << "\n";
}

void bank::withdraw_money() {
    int withdraw;
    cout << "Enter amount to withdraw: ";
    cin >> withdraw;
    if (withdraw > balance) {
        cout << "Insufficient balance!\n";
    } else {
        balance -= withdraw;
        cout << "Amount withdrawn successfully! Current balance: " << balance << "\n";
    }
}

void bank::display_account() {
    cout << "Full Name: " << name << "\n";
    cout << "Address: " << address << "\n";
    cout << "Account Type: " << accountType << "\n";
    cout << "Balance: " << balance << "\n";
}

int main() {
    bank obj;
    int choice;

    do {
        cout << "\n1: Open Account";
        cout << "\n2: Deposit Money";
        cout << "\n3: Withdraw Money";
        cout << "\n4: Display Account";
        cout << "\n5: Exit";
        cout << "\nSelect an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.open_account();
                break;
            case 2:
                obj.deposit_money();
                break;
            case 3:
                obj.withdraw_money();
                break;
            case 4:
                obj.display_account();
                break;
            case 5:
                cout << "Thank you for using our bank system. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (true);

    return 0;
}
