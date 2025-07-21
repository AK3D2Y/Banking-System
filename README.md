C++ Command-Line Banking System
This is a simple but complete command-line banking application written in C++. It demonstrates fundamental Object-Oriented Programming (OOP) principles and file handling for data persistence.

Description
The application simulates a basic banking system where a user can perform standard banking operations. All account data is saved to a local file (bank.data), so the information persists across multiple sessions. The system is designed with two main classes: account to represent individual accounts, and bank to manage all the accounts.

Features
Open an Account: Create a new bank account with a unique, auto-generated account number.

Balance Enquiry: Check the current balance and details of an existing account.

Deposit: Add funds to an account.

Withdraw: Remove funds from an account, with checks for insufficient balance.

Close an Account: Delete an existing account from the system.

Show All Accounts: Display a list of all accounts currently in the bank.

Data Persistence: Account data is automatically loaded from bank.data on startup and saved back to the file on exit.

Concepts Demonstrated
This project was built to practice and showcase the following C++ and OOP concepts:

Object-Oriented Programming:

Classes and Objects: account and bank classes as blueprints for objects.

Encapsulation: Using public and private access specifiers to protect data.

Constructors and Destructors: For automatic setup (loading data) and cleanup (saving data).

C++ Standard Library:

Using the std::map container for efficient, key-based data storage and retrieval.

Standard I/O streams (iostream) for user interaction.

File I/O streams (fstream) for reading from and writing to files.

Operator Overloading: Overloading the << and >> operators for easy printing and file I/O of account objects.

Static Members: Using a static variable to ensure unique account numbers are generated for every new account.

How to Compile and Run
Prerequisites: You need a C++ compiler (like g++).

Save the Code: Save the code into a file named banking.cpp.

Compile: Open a terminal or command prompt and run the following command:

g++ banking.cpp -o banking_app

Run: Execute the compiled program:

./banking_app

The application will start, and a bank.data file will be created in the same directory to store account information.
