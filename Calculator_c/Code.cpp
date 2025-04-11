// Specialized Calculator - Handles Basic and Additional Operations
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits> // For precise comparisons

using namespace std;

// Addition function
int add(int x, int y) {
  return x + y;
}

// Subtraction function
int sub(int x, int y) {
  return x - y;
}

// Multiplication function
int multi(int x, int y) {
  return x * y;
}

// Division function with error check
int div(int x, int y) {
  if (y == 0) {
    cout << "Error: Division by zero is not allowed." << endl;
    return 0; // Prevent crash
  }
  return x / y;
}

// String output for division results (with quotient and remainder)
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

// This function calculates the nth root of a number using Newton-Raphson method
double nthRoot(double value, int n, double tolerance = 1e-10, int maxIterations = 1000) {
  // Error check: Even root of negative numbers is invalid (e.g., √-16 is imaginary)
  if (value < 0 && n % 2 == 0) {
    throw invalid_argument("Even root of negative number is not real.");
  }

  // Error check: n must be a positive number
  if (n <= 0) {
    throw invalid_argument("Root must be a positive integer.");
  }

  // Initial guess for root (a reasonable starting point)
  double x = value / n;

  // Loop to improve the guess using Newton's formula
  for (int i = 0; i < maxIterations; ++i) {
    double prev = x; // Save current guess
    // Newton-Raphson formula to update the guess
    x = ((n - 1) * x + value / pow(x, n - 1)) / n;

    // If the guess is close enough to the actual root, stop
    if (abs(x - prev) < tolerance) break;
  }

  return x; // Return the final guess (very close to the real root)
}

// Handles basic operations: +, -, *, /
int Basic_ops() {
  cout << "Welcome to the basic operations section!" << endl;
  cout << "Which operation do you want to perform?" << endl;
  cout << "Addition (A), Subtraction (S), Multiplication (M), Division (D): ";
  char op;
  cin >> op;

  int x, y;
  cout << "Enter first number: ";
  cin >> x;
  cout << "Enter second number: ";
  cin >> y;

  // Decision based on chosen operation
  if (op == 'a' || op == 'A') {
    cout << "The sum of " << x << " and " << y << " is: " << add(x, y) << endl;
  } else if (op == 's' || op == 'S') {
    cout << "The difference of " << x << " and " << y << " is: " << sub(x, y) << endl;
  } else if (op == 'm' || op == 'M') {
    cout << "The product of " << x << " and " << y << " is: " << multi(x, y) << endl;
  } else if (op == 'd' || op == 'D') {
    cout << div_print(x, y) << endl;
  } else {
    cout << "Invalid operation" << endl;
  }
  return 0;
}

// Handles additional operations: Power and Root
int AdditionalOps() {
  char op;
  int x, y;
  double result;

  cout << "Welcome to the additional operations section!\n";
  cout << "Which operation do you want to perform?\n";
  cout << "Exponentiation(E)/Powering(P) or Rooting(R): ";
  cin >> op;

  // POWER OPERATION
  if (op == 'e' || op == 'E' || op == 'p' || op == 'P') {
    cout << "What is the base?: ";
    cin >> x;
    cout << "What is the exponent?: ";
    cin >> y;

    result = pow(x, y); // Built-in power function
    cout << "\nThe result of " << x << "^" << y << " is " << result << endl;

  // ROOT OPERATION
  } else if (op == 'r' || op == 'R') {
    cout << "What number is being rooted? (Ex: √16): ";
    cin >> x;

    cout << "What is the index (Ex: 2 for square root, 3 for cube root, etc.): ";
    cin >> y;

    try {
      result = nthRoot(x, y); // Call our custom root function
      cout << "The root result of " << y << "√" << x << " is " << result << endl;
    } catch (const exception& e) {
      // Catch and display errors like negative root issues
      cout << "Error: " << e.what() << endl;
    }

  } else {
    cout << "Invalid operation choice." << endl;
  }

  return 0;
}

// Main menu to select between basic and additional operations
int main() {
  cout << "Welcome to the specialized calculator!" << endl;
  cout << "It has 2 sections: Basic and Additional." << endl;
  cout << "Do you want to perform basic operations or additional operations? (B=Basic, A=Additional): ";
  char BasicFunction;
  cin >> BasicFunction;

  if (BasicFunction == 'b' || BasicFunction == 'B') {
    Basic_ops();

    // Ask user if they also want to do additional operations
    cout << "Do you want to also perform additional operations? (yes=y, no=n): ";
    char AdditionalFunction;
    cin >> AdditionalFunction;
    if (AdditionalFunction == 'y' || AdditionalFunction == 'Y') {
      AdditionalOps();
    } else {
      cout << "Thank you for using the specialized calculator!" << endl;
    }

  } else if (BasicFunction == 'a' || BasicFunction == 'A') {
    AdditionalOps();

    // Ask user if they also want to do basic operations
    cout << "Do you want to also perform basic operations? (yes=y, no=n): ";
    char BasicRepeat;
    cin >> BasicRepeat;
    if (BasicRepeat == 'y' || BasicRepeat == 'Y') {
      Basic_ops();
    } else {
      cout << "Thank you for using the specialized calculator!" << endl;
    }

  } else {
    // Catch invalid menu selection
    cout << "Invalid input. Please enter 'B' for basic or 'A' for additional operations." << endl;
  }

  return 0;
}
