C++ Command-Line Banking System 🏦
A complete command-line banking application built in C++ to demonstrate core Object-Oriented Programming (OOP) principles and data persistence.

 Features :
Interactive Functionality: Manage accounts directly from your terminal.

Unique Account IDs: New accounts are automatically assigned a unique, incrementing number.

Robust Error Handling: The application gracefully handles invalid inputs and non-existent accounts.

Data Persistence: Account data is automatically saved to bank.data on exit and reloaded on startup.

 Tech Stack & Concepts :
Language: C++17

Core Libraries: iostream, fstream, map

Key Concepts:

Object-Oriented Programming (Classes, Encapsulation, Constructors/Destructors)

STL Containers (std::map for efficient lookups)

File I/O for data persistence

Operator Overloading (<< and >>)

⚙️ How to Run
To run this project on your local machine, follow these simple steps.

Prerequisite: Ensure you have a C++ compiler installed (like g++ or clang++).

Save the Code: Save the source code into a file named banking.cpp.

Compile the Application:
Open your terminal and run the appropriate command:

# If using g++
g++ -std=c++17 banking.cpp -o banking_app

# If using clang++
clang++ -std=c++17 banking.cpp -o banking_app

Run the Program!
Execute the compiled file from your terminal:

./banking_app
 
Developer's Note :
My primary goal for this project was to build a robust application that correctly manages its own state. I chose to handle data persistence by using the constructor and destructor of the bank class.

The constructor automatically loads all account data from bank.data the moment the program starts.

The destructor automatically saves all data back to the file when the program quits.

This design pattern (known as RAII - Resource Acquisition Is Initialization) ensures that data is always loaded and saved correctly without needing manual function calls in main. It makes the application more resilient and the main logic cleaner. For this project, I felt this automated, object-oriented approach was a more robust solution than manual file handling.
