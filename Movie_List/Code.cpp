#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct to store movie information
struct M_info {
  string title; // Movie title
  int year;     // Year of release
  double price; // Price of the movie
};

// Function to display movie details
// Takes a constant reference to an M_info object to avoid copying
void Movie_O(const M_info &movie) {
  cout << "The title of the movie is: " << movie.title << endl;
  cout << "The year of release is: " << movie.year << endl;
  cout << "The price of the movie nowadays is: $" << movie.price + 1.0 << endl;
}

// Function to input movie details
// Takes a reference to an M_info object to update its fields
void Movie_I(M_info &movie) {
  cout << "What is the title of the movie?: ";
  cin >> movie.title; // Input movie title
  cout << "What is the year of release?: ";
  cin >> movie.year; // Input year of release
  cout << "What is the price of the movie?: ";
  cin >> movie.price; // Input price of the movie
}

int main() {
  cout << "Welcome to the Movie Database!" << endl;

  vector<M_info> movies; // Dynamic list of movies
  char choice; // Variable to store user's choice to continue or stop

  // Loop to allow the user to input multiple movies
  do {
    M_info movie; // Temporary variable to store movie details
    cout << "Enter details for a new movie:" << endl;
    Movie_I(movie); // Input movie details
    movies.push_back(movie); // Add the movie to the list

    // Ask the user if they want to enter another movie
    cout << "Do you want to enter another movie? (y/n): ";
    cin >> choice;
  } 
  while (choice == 'y' || choice == 'Y'); // Continue if the user enters 'y' or 'Y'  
  // Output all movie details
  cout << "\nMovie Details:" << endl;
  for (size_t i = 0; i < movies.size(); i++) {
    cout << "Movie " << i + 1 << ":" << endl;
    Movie_O(movies[i]); // Display movie details
    cout << endl;
  }

  // Thank the user for using the program
  cout << "Thank you for using the Movie Database!" << endl;
  cout << "Have a nice day!" << endl;

  // Terminates the program
  return 0;
}