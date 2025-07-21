#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits> // Required for numeric_limits

// Forward declaration of the bank class
class bank;

// The account class represents a single bank account.
// It manages the account details, deposits, and withdrawals.
class account {
private:
    long accountNumber;
    std::string firstName;
    std::string lastName;
    float balance;
    // Static member to track the next available account number
    static long nextAccountNumber;

public:
    // Default constructor
    account() : accountNumber(0), firstName(""), lastName(""), balance(0.0f) {}

    // Parameterized constructor to create a new account
    account(std::string fname, std::string lname, float balance);

    // Accessor methods to get account details
    long getAccountNumber() const { return accountNumber; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    float getBalance() const { return balance; }

    // Member functions for account operations
    void deposit(float amount);
    void withdraw(float amount);

    // Static methods to manage the global last account number
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();

    // Friend functions for file and console I/O operations
    friend std::ofstream& operator<<(std::ofstream& ofs, const account& acc);
    friend std::ifstream& operator>>(std::ifstream& ifs, account& acc);
    friend std::ostream& operator<<(std::ostream& os, const account& acc);
};

// Initialize the static member variable
long account::nextAccountNumber = 0;

// The bank class manages all the accounts in the system.
// It handles opening, closing, and performing transactions on accounts.
class bank {
private:
    // A map to store accounts, with the account number as the key
    std::map<long, account> accounts;

public:
    // Constructor: Loads accounts from a file upon creation
    bank();

    // Member functions for bank operations
    account openAccount(std::string fname, std::string lname, float balance);
    account balanceEnquiry(long accountNumber);
    account deposit(long accountNumber, float amount);
    account withdraw(long accountNumber, float amount);
    void closeAccount(long accountNumber);
    void showAllAccounts();

    // Destructor: Saves all accounts to a file upon destruction
    ~bank();
};

// Main function - the entry point of the program
int main() {
    bank b;
    account acc;

    int choice = 0; // Initialize choice to 0
    std::string fname, lname;
    long accountNumber;
    float balance;
    float amount;

    std::cout << "***** BANKING SYSTEM *****" << "\n";
    while (choice != 7) {
        // Display the menu
        std::cout << "\n\tSelect one option below:";
        std::cout << "\n\t1 Open an Account";
        std::cout << "\n\t2 Balance Enquiry";
        std::cout << "\n\t3 Deposit";
        std::cout << "\n\t4 Withdraw";
        std::cout << "\n\t5 Close an Account";
        std::cout << "\n\t6 Show All Accounts";
        std::cout << "\n\t7 Quit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        // Handle potential input errors
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "\nInvalid input. Please enter a number.\n";
            choice = 0; // Reset choice to avoid infinite loop
            continue; // Skip the rest of the loop
        }


        switch (choice) {
            case 1:
                std::cout << "Enter First Name: ";
                std::cin >> fname;
                std::cout << "Enter Last Name: ";
                std::cin >> lname;
                std::cout << "Enter Initial Balance: ";
                std::cin >> balance;
                acc = b.openAccount(fname, lname, balance);
                std::cout << "\nCongratulations! Account is Created successfully:\n";
                std::cout << acc;
                break;
            case 2:
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                acc = b.balanceEnquiry(accountNumber);
                std::cout << "\nYour Account Details:\n";
                std::cout << acc;
                break;
            case 3:
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout << "Enter Amount to Deposit: ";
                std::cin >> amount;
                acc = b.deposit(accountNumber, amount);
                std::cout << "\nAmount is Deposited successfully\n";
                std::cout << "Updated Account Details:\n";
                std::cout << acc;
                break;
            case 4:
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout << "Enter Amount to Withdraw: ";
                std::cin >> amount;
                acc = b.withdraw(accountNumber, amount);
                std::cout << "\nAmount Withdrawn successfully\n";
                std::cout << "Updated Account Details:\n";
                std::cout << acc;
                break;
            case 5:
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                b.closeAccount(accountNumber);
                break;
            case 6:
                b.showAllAccounts();
                break;
            case 7:
                std::cout << "\nThank you for using our banking system!\n";
                break;
            default:
                std::cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}

// --- account Class Member Function Implementations ---

account::account(std::string fname, std::string lname, float balance) {
    nextAccountNumber++;
    accountNumber = nextAccountNumber;
    firstName = fname;
    lastName = lname;
    this->balance = balance;
}

void account::deposit(float amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        std::cout << "Deposit amount must be positive.\n";
    }
}

void account::withdraw(float amount) {
    if (amount <= 0) {
        std::cout << "Withdrawal amount must be positive.\n";
    } else if (balance >= amount) {
        balance -= amount;
    } else {
        std::cout << "Error: Insufficient funds.\n";
    }
}

void account::setLastAccountNumber(long accountNumber) {
    nextAccountNumber = accountNumber;
}

long account::getLastAccountNumber() {
    return nextAccountNumber;
}

// Overloads the << operator to write account data to a file
std::ofstream& operator<<(std::ofstream& ofs, const account& acc) {
    ofs << acc.accountNumber << "\n";
    ofs << acc.firstName << "\n";
    ofs << acc.lastName << "\n";
    ofs << acc.balance << "\n";
    return ofs;
}

// Overloads the >> operator to read account data from a file
std::ifstream& operator>>(std::ifstream& ifs, account& acc) {
    ifs >> acc.accountNumber;
    ifs >> acc.firstName;
    ifs >> acc.lastName;
    ifs >> acc.balance;
    return ifs;
}

// Overloads the << operator to display account details on the console
std::ostream& operator<<(std::ostream& os, const account& acc) {
    os << "------------------------\n";
    os << "Account Number: " << acc.getAccountNumber() << "\n";
    os << "First Name: " << acc.getFirstName() << "\n";
    os << "Last Name: " << acc.getLastName() << "\n";
    os << "Balance: " << acc.getBalance() << "\n";
    os << "------------------------\n";
    return os;
}

// --- bank Class Member Function Implementations ---

bank::bank() {
    account acc;
    std::ifstream infile("bank.data");

    // Check if the file can be opened
    if (!infile) {
        // No file exists, which is fine for the first run.
        return;
    }

    // Read account data from the file until the end
    while (infile >> acc) {
        accounts.insert(std::make_pair(acc.getAccountNumber(), acc));
    }

    // Set the next account number based on the last account read
    if (acc.getAccountNumber() > 0) {
        account::setLastAccountNumber(acc.getAccountNumber());
    }

    infile.close();
}

account bank::openAccount(std::string fname, std::string lname, float balance) {
    account acc(fname, lname, balance);
    accounts.insert(std::make_pair(acc.getAccountNumber(), acc));

    // Append the new account to the file immediately for persistence
    std::ofstream outfile("bank.data", std::ios::app);
    outfile << acc;
    outfile.close();

    return acc;
}

account bank::balanceEnquiry(long accountNumber) {
    auto itr = accounts.find(accountNumber);
    if (itr == accounts.end()) {
        std::cout << "Error: Account not found.\n";
        return account(); // Return an empty account object
    }
    return itr->second;
}

account bank::deposit(long accountNumber, float amount) {
    auto itr = accounts.find(accountNumber);
    if (itr == accounts.end()) {
        std::cout << "Error: Account not found.\n";
        return account();
    }
    itr->second.deposit(amount);
    return itr->second;
}

account bank::withdraw(long accountNumber, float amount) {
    auto itr = accounts.find(accountNumber);
    if (itr == accounts.end()) {
        std::cout << "Error: Account not found.\n";
        return account();
    }
    itr->second.withdraw(amount);
    return itr->second;
}

void bank::closeAccount(long accountNumber) {
    auto itr = accounts.find(accountNumber);
    if (itr == accounts.end()) {
        std::cout << "Error: Account not found.\n";
        return;
    }
    std::cout << "Account Deleted:\n" << itr->second;
    accounts.erase(accountNumber);
}

void bank::showAllAccounts() {
    if (accounts.empty()) {
        std::cout << "\nNo accounts in the bank.\n";
        return;
    }
    for (auto const& [accNum, acc] : accounts) {
        std::cout << "Account " << accNum << "\n" << acc << "\n";
    }
}

bank::~bank() {
    std::ofstream outfile("bank.data", std::ios::trunc); // Use trunc to overwrite the file
    if (!outfile) {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }
    for (auto const& [accNum, acc] : accounts) {
        outfile << acc;
    }
    outfile.close();
}
