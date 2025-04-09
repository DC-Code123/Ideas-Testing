//Yoooo This should work
#include <iostream>
#include <string>
#include <sstream>
#include <cmath> 

using namespace std;
//function for addition
int add(int x, int y) {
  return x + y;
}
//function for subtraction
int sub(int x, int y) {
  return x - y;
}
//function for multiplication
int multi(int x, int y) {
  return x * y;
}
//function for division
int div(int x, int y) {

  if (y == 0) {
    cout << "Error: Division by zero is not allowed." << endl;
    return 0; // Return 0 to indicate an error
  }

  return x / y;
}
//function for printing the result of division
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
//Main function for all operations
int main(){
  cout<<"Welcome to the specialized calculator!"<<endl;
  cout<<"It has 2 sectons: Basic and Additional."<<endl;
  cout<<"Do you want to perform basic operations or additional operations? (B=basic, A=Additional): ";
  char BasicFunction;
  cin >> BasicFunction;
  if (BasicFunction =='b'||BasicFunction=='B'){
    Basic_ops();
    cout<<"Do you want to also perform additional operations? (yes=y, no=n): ";
    char AdditionalFunction;
    cin >> AdditionalFunction;
    if (AdditionalFunction=='y'||AdditionalFunction=='Y'){
      Additional_ops();
    }
    else if (AdditionalFunction=='n'||AdditionalFunction=='N'){
      cout<<"Thank you for using the specialized calculator!"<<endl;
    }
    else {
      cout<<"Invalid input. Please enter 'y' for yes or 'n' for no."<<endl;
    }
    return 0
  }
  else if (BasicFunction=='a'||BasicFunction=='A'){
    Additional_ops();
    cout<<"Do you want to also perform basic operations? (yes=y, no=n): ";
    char BasicFunction;
    cin >> BasicFunction;
    if (BasicFunction=='y'||BasicFunction=='Y'){
      Basic_ops();
    }
    else if (BasicFunction=='n'||BasicFunction=='N'){
      cout<<"Thank you for using the specialized calculator!"<<endl;
    }
    else {
      cout<<"Invalid input. Please enter 'y' for yes or 'n' for no."<<endl;
    }
  }
  else {
    cout<<"Invalid input. Please enter 'B' for basic operations or 'A' for additional operations."<<endl;

  }
  return 0;
}
int Basic_ops(){
  cout<<"Welcome to the basic operations section!"<<endl;
  cout<<"Which operation do you want to preform?"<<endl;
  cout<<"Addition (A), Subtraction (S), Multiplication (M), Division (D): ";
  char op;
  cin >> op;
  int x, y;
  cout << "Enter first number: ";
  cin >> x;
  cout << "Enter second number: ";
  cin >> y;
  if (op == 'a' || op == 'A') {
    cout << "The sum of " << x << " and " << y << " is: " << add(x, y) << endl;
    int sum = add(x, y);
  } else if (op == 's' || op == 'S') {
    cout << "The difference of " << x << " and " << y << " is: " << sub(x, y) << endl;
    int diff = sub(x, y);
  } else if (op == 'm' || op == 'M') {
    cout << "The product of " << x << " and " << y << " is: " << multi(x, y) << endl;
    int prod = multi(x, y);
  } else if (op == 'd' || op == 'D') {
    cout<<div_print(x,y)<<endl;
    int quot = div(x, y);
    int mod = x % y;
  } else {
    cout<<"Invalid operation"<<endl;
  }
  return 0;
}