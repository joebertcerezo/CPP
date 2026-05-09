#include <iostream>
#include <string>

using namespace std;

// This file covers basic input/output, variables, data types, and control flow.

int main() {
  // 1. Outputs
  cout << "--- Basics in C++ ---" << "\n";

  // 2. Variables & Data Types
  int age = 25;
  double pi = 3.14159;
  char grade = 'A';
  bool isPassed = true;
  string name = "Alice";

  cout << "Name: " << name << ", Age: " << age << "\n";

  // 3. User Input
  cout << "Enter your favorite number: ";
  int favNum;
  // cin >> favNum;   // Uncomment to take input
  favNum = 7; // Hardcoded for demonstration
  cout << "You chose " << favNum << ".\n";

  // 4. Control Flow (If-Else)
  if (age >= 18) {
    cout << "Adult\n";
  } else {
    cout << "Minor\n";
  }

  // 5. Loops (For, While, Do-While)
  cout << "Counting: ";
  for (int i = 1; i <= 3; ++i) {
    cout << i << " ";
  }
  cout << "\n";

  return 0;
}
