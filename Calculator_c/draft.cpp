#include <iostream>
#include <string>
#include <sstream>
#include <cmath> 

using namespace std;

// Function for addition
int add(int x, int y) {
  return x + y;
}

// Function for subtraction
int sub(int x, int y) {
  return x - y;
}

// Function for multiplication
int multi(int x, int y) {
  return x * y;
}

// Function for division
int div(int x, int y) {
  if (y == 0) {
    cout << "Error: Division by zero is not allowed." << endl;
    return 0; // Return 0 to indicate an error
  }
  return x / y;
}

// Function for printing the result of division
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

// Function for basic operations
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
  if (op == 'a' || op == 'A') {
    cout << "The sum of " << x << " and " << y << " is: " << add(x, y) << endl;
  } 
  else if (op == 's' || op == 'S') {
    cout << "The difference of " << x << " and " << y << " is: " << sub(x, y) << endl;
  } 
  else if (op == 'm' || op == 'M') {
    cout << "The product of " << x << " and " << y << " is: " << multi(x, y) << endl;
  } 
  else if (op == 'd' || op == 'D') {
    cout << div_print(x, y) << endl;
  } 
  else {
    cout << "Invalid operation" << endl;
  }
  return 0;
}

// Function for additional operations
int Additional_ops() {
  cout << "Welcome to the additional operations section!" << endl;
  cout << "Which operation do you want to perform?" << endl;
  cout << "Exponentiation (E), Square Root (S): ";
  char op;
  cin >> op;

  if (op == 'e' || op == 'E') {
    double base, exponent;
    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;
    cout << base << " raised to the power of " << exponent << " is: " << pow(base, exponent) << endl;
  } 
  else if (op == 's' || op == 'S') {
    double number;
    cout << "Enter a number to find its square root: ";
    cin >> number;
    if (number < 0) {
      cout << "Square root of a negative number is not defined in real numbers." << endl;
    } 
    else {
      cout << "The square root of " << number << " is: " << sqrt(number) << endl;
    }
  } 
  else {
    cout << "Invalid operation" << endl;
  }
  return 0;
}

// Main function
int main() {
  cout << "Welcome to the specialized calculator!" << endl;
  cout << "It has 2 sections: Basic and Additional." << endl;
  cout << "Do you want to perform basic operations or additional operations? (B=basic, A=Additional): ";
  char BasicFunction;
  cin >> BasicFunction;
  if (BasicFunction == 'b' || BasicFunction == 'B') {
    Basic_ops();
    cout << "Do you want to also perform additional operations? (yes=y, no=n): ";
    char AdditionalFunction;
    cin >> AdditionalFunction;
    if (AdditionalFunction == 'y' || AdditionalFunction == 'Y') {
      Additional_ops();
    } 
    else if (AdditionalFunction == 'n' || AdditionalFunction == 'N') {
      cout << "Thank you for using the specialized calculator!" << endl;
    } 
    else {
      cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
    }
    return 0;
  } 
  else if (BasicFunction == 'a' || BasicFunction == 'A') {
    Additional_ops();
    cout << "Do you want to also perform basic operations? (yes=y, no=n): ";
    char PerformBasic;
    cin >> PerformBasic;
    if (PerformBasic == 'y' || PerformBasic == 'Y') {
      Basic_ops();
    } 
    else if (PerformBasic == 'n' || PerformBasic == 'N') {
      cout << "Thank you for using the specialized calculator!" << endl;
    } 
    else {
      cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
    }
  } 
  else {
    cout << "Invalid input. Please enter 'B' for basic operations or 'A' for additional operations." << endl;
  }
  return 0;
}