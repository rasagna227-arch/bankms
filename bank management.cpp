#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bank
{
public:
    int accNo;
    string name;
    float balance;
};

void createAccount()
{
    Bank b;

    ofstream file("bank.txt", ios::app);

    cout << "\nEnter Account Number: ";
    cin >> b.accNo;

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, b.name);

    cout << "Enter Initial Balance: ";
    cin >> b.balance;

    file << b.accNo << endl;
    file << b.name << endl;
    file << b.balance << endl;

    file.close();

    cout << "\nAccount Created Successfully!\n";
}

void displayAccounts()
{
    Bank b;

    ifstream file("bank.txt");

    cout << "\n====== ALL ACCOUNT DETAILS ======\n";

    while (file >> b.accNo)
    {
        file.ignore();

        getline(file, b.name);

        file >> b.balance;

        file.ignore();

        cout << "\nCustomer ID      : " << b.accNo;
        cout << "\nCustomer Name    : " << b.name;
        cout << "\nCurrent Balance  : " << b.balance;

        cout << "\n----------------------------------\n";
    }

    file.close();
}

void depositMoney()
{
    int account;
    float amount;

    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> account;

    cout << "Enter Deposit Amount: ";
    cin >> amount;

    Bank b;

    ifstream file("bank.txt");
    ofstream temp("temp.txt");

    while (file >> b.accNo)
    {
        file.ignore();

        getline(file, b.name);

        file >> b.balance;

        file.ignore();

        if (b.accNo == account)
        {
            b.balance = b.balance + amount;
            found = true;
        }

        temp << b.accNo << endl;
        temp << b.name << endl;
        temp << b.balance << endl;
    }

    file.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (found)
        cout << "\nAmount Deposited Successfully!\n";
    else
        cout << "\nAccount Not Found!\n";
}

void withdrawMoney()
{
    int account;
    float amount;

    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> account;

    cout << "Enter Withdrawal Amount: ";
    cin >> amount;

    Bank b;

    ifstream file("bank.txt");
    ofstream temp("temp.txt");

    while (file >> b.accNo)
    {
        file.ignore();

        getline(file, b.name);

        file >> b.balance;

        file.ignore();

        if (b.accNo == account)
        {
            found = true;

            if (b.balance >= amount)
            {
                b.balance = b.balance - amount;

                cout << "\nWithdrawal Successful!\n";
            }
            else
            {
                cout << "\nInsufficient Balance!\n";
            }
        }

        temp << b.accNo << endl;
        temp << b.name << endl;
        temp << b.balance << endl;
    }

    file.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (!found)
        cout << "\nAccount Not Found!\n";
}

void checkBalance()
{
    int account;

    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> account;

    Bank b;

    ifstream file("bank.txt");

    while (file >> b.accNo)
    {
        file.ignore();

        getline(file, b.name);

        file >> b.balance;

        file.ignore();

        if (b.accNo == account)
        {
            cout << "\nCustomer ID      : " << b.accNo;
            cout << "\nCustomer Name    : " << b.name;
            cout << "\nCurrent Balance  : " << b.balance;

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nAccount Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";

        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;

        case 2:
            depositMoney();
            break;

        case 3:
            withdrawMoney();
            break;

        case 4:
            checkBalance();
            break;

        case 5:
            displayAccounts();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}