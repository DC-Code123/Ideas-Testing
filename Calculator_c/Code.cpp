// Specialized Calculator - Handles Basic and Additional Operations
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits> // For precise comparisons and handling large/small values

using namespace std;

// Function to add two numbers
int add(int x, int y) {
  return x + y;
}

// Function to subtract second number from first
int sub(int x, int y) {
  return x - y;
}

// Function to multiply two numbers
int multi(int x, int y) {
  return x * y;
}

// Function to divide two numbers with error checking
int mydiv(int x, int y) {
  if (y == 0) { // Check for division by zero
    cout << "Error: Division by zero is not allowed." << endl;
    return 0;
  }
  return x / y;
}

// Function to print the result of division with quotient and remainder
string div_print(int x, int y) {
  if (y == 0) {
    return "Error: Division by zero is not allowed.";
  }
  int quotient = x / y;
  int remainder = x % y;
  stringstream ss;
  ss << "The quotient of " << x << " and " << y << " is: " << quotient
     << ", and the remainder is: " << remainder;
  return ss.str();
}

// Function to calculate the nth root using Newton-Raphson method
// This is a numerical approach to approximate roots
double nthRoot(double value, int n, double tolerance = 1e-10, int maxIterations = 1000) {
  if (value < 0 && n % 2 == 0) {
    throw invalid_argument("Even root of negative number is not real.");
  }
  if (n <= 0) {
    throw invalid_argument("Root must be a positive integer.");
  }

  double x = value / n; // Starting guess for root

  for (int i = 0; i < maxIterations; ++i) {
    double prev = x; // Store previous guess
    x = ((n - 1) * x + value / pow(x, n - 1)) / n; // Update guess using formula
    if (abs(x - prev) < tolerance) break; // Stop if the guess is accurate enough
  }

  return x; // Return the final result
}

// Function to handle basic operations: +, -, *, /
int Basic_ops() {
  cout << "\n--- Basic Operations ---" << endl;
  cout << "Choose operation: Addition (A), Subtraction (S), Multiplication (M), Division (D): ";
  char op;
  cin >> op;

  int x, y;
  cout << "Enter first number: ";
  cin >> x;
  cout << "Enter second number: ";
  cin >> y;

  // Check and perform selected operation
  if (op == 'a' || op == 'A') {
    cout << "Result: " << x << " + " << y << " = " << add(x, y) << endl;
  } else if (op == 's' || op == 'S') {
    cout << "Result: " << x << " - " << y << " = " << sub(x, y) << endl;
  } else if (op == 'm' || op == 'M') {
    cout << "Result: " << x << " * " << y << " = " << multi(x, y) << endl;
  } else if (op == 'd' || op == 'D') {
    cout << div_print(x, y) << endl; // Uses the division result string function
  } else {
    cout << "Invalid operation choice." << endl;
  }
  return 0;
}

// Function to handle additional operations: power and root
int AdditionalOps() {
  char op;
  int x, y;
  double result;

  cout << "\n--- Additional Operations ---" << endl;
  cout << "Choose operation: Powering (P) or Rooting (R): ";
  cin >> op;

  if (op == 'e' || op == 'E' || op == 'p' || op == 'P') {
    cout << "Enter base: ";
    cin >> x;
    cout << "Enter exponent: ";
    cin >> y;
    result = pow(x, y); // Standard library function for power
    cout << "Result: " << x << "^" << y << " = " << result << endl;
  } else if (op == 'r' || op == 'R') {
    cout << "Enter the number to be rooted: ";
    cin >> x;
    cout << "Enter the index of the root (e.g., 2 for square root): ";
    cin >> y;
    try {
      result = nthRoot(x, y); // Use custom root function
      cout << "Result: " << y << "√" << x << " = " << result << endl;
    } catch (const exception& e) {
      cout << "Error: " << e.what() << endl; // Display error message
    }
  } else {
    cout << "Invalid additional operation choice." << endl;
  }
  return 0;
}

// Main function - shows main menu and loops until user exits
int main() {
  while (true) { // Infinite loop until user chooses to exit
    cout << "\n===== Specialized Calculator =====" << endl;
    cout << "Choose operation type:" << endl;
    cout << "(B)asic, (A)dditional, or (E)xit: ";

    char choice;
    cin >> choice;

    if (choice == 'b' || choice == 'B') {
      Basic_ops(); // Call basic operations menu
    } else if (choice == 'a' || choice == 'A') {
      AdditionalOps(); // Call additional operations menu
    } else if (choice == 'e' || choice == 'E') {
      cout << "Exiting calculator. Goodbye!" << endl;
      break; // Exit the loop and end program
    } else {
      cout << "Invalid input. Please enter B, A, or E." << endl;
    }
  }
  return 0;
}
