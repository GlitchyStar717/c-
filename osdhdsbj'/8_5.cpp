#include <fstream>
#include <iostream>
#include    <stdlib.h>
#include <ctime>

using namespace std;

// Class to represent account information
class Account {
    string accountNumber;
    string lastName;
    string firstName;
    double totalBalance;

   public:
    // Constructor
    Account(string accNum= "0000000000", string last = "Ghimire", string first = "Samip", double balance = 100000) {
        accountNumber = accNum;
        lastName = last;
        firstName = first;
        totalBalance = balance;
    }

    // Function to display account information
    void displayAccount() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Total Balance: $" << totalBalance << endl;
        cout << "-------------------------" << endl;
    }
};

// Function to generate a random account number
string generateRandomAccountNumber() {
    char accNum[11];
    int i = 0;
    unsigned long int  number =  rand() % 1000000000 + 1000000000;  // Generate a random number between 1000 and 1999
    while (number!=0){
        accNum[10-i++] = number%10;
        number = number/10;
    }
    return accNum;
    
   
}



// Function to add an account record to the random access file
void addAccountRecord(fstream& file) {
    string lastName, firstName, accountNumber;
    double totalBalance;


    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Total Balance: $";
    cin >> totalBalance;

    accountNumber = static_cast<string>(generateRandomAccountNumber());
    Account newAccount(accountNumber, lastName, firstName, totalBalance);

    file.write(reinterpret_cast<const char*>(&newAccount), sizeof(Account));
    cout << "Account added successfully." << endl;
}

// Function to display an account record from the random access file
void displayAccountRecord(fstream& file, int accountNumber) {
    file.seekg((accountNumber - 1000) * sizeof(Account), ios::beg);
    Account account;

    if (file.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        account.displayAccount();
    } else {
        cout << "Account not found." << endl;
    }
}

// Function to update an account record in the random access file
void updateAccountRecord(fstream& file, int accountNumber) {
    file.seekg((accountNumber - 1000) * sizeof(Account), ios::beg);
    Account account;

    if (file.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        account.displayAccount();

        string lastName, firstName;
        double totalBalance;

        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Total Balance: $";
        cin >> totalBalance;

        account.lastName = lastName;
        account.firstName = firstName;
        account.totalBalance = totalBalance;

        file.seekp((accountNumber - 1000) * sizeof(Account), ios::beg);
        file.write(reinterpret_cast<const char*>(&account), sizeof(Account));
        cout << "Account updated successfully." << endl;
    } else {
        cout << "Account not found." << endl;
    }
}

// Function to delete an account record from the random access file
void deleteAccountRecord(fstream& file, int accountNumber) {
    file.seekg((accountNumber - 1000) * sizeof(Account), ios::beg);
    Account account;

    if (file.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        account.displayAccount();
        cout << "Are you sure you want to delete this account? (Y/N): ";
        char choice;
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            // Mark the account as deleted by setting the account number to -1
            account.accountNumber = -1;
            file.seekp((accountNumber - 1000) * sizeof(Account), ios::beg);
            file.write(reinterpret_cast<const char*>(&account), sizeof(Account));
            cout << "Account deleted successfully." << endl;
        }
    } else {
        cout << "Account not found." << endl;
    }
}

int main() {
    fstream file("accounts.dat", ios::in | ios::out | ios::binary);
    srand(static_cast<unsigned>(time(0)));

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int choice, accountNumber;

    do {
        cout << "1. Add Account\n";
        cout << "2. Display Account\n";
        cout << "3. Update Account\n";
        cout << "4. Delete Account\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAccountRecord(file);
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                displayAccountRecord(file, accountNumber);
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                updateAccountRecord(file, accountNumber);
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                deleteAccountRecord(file, accountNumber);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    file.close();
    return 0;
}