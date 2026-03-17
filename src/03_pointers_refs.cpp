#include <iostream>

using namespace std;

// This file covers pointers and references, a core concept in C++.

int main() {
  cout << "--- Pointers & References ---\n";

  int score = 100;

  // 1. References (Alias for an existing variable)
  int &scoreRef = score;
  scoreRef = 110; // Changes 'score' directly
  cout << "Score via reference: " << score << "\n";

  // 2. Pointers (Holds memory address of a variable)
  int *ptr = &score;

  cout << "Address of score: " << ptr << "\n";
  cout << "Value via pointer (Dereferencing): " << *ptr << "\n";

  // Modifying value via pointer
  *ptr = 120;
  cout << "Modified score via pointer: " << score << "\n";

  // 3. Null Pointers
  int *nullPtr = nullptr;
  if (nullPtr == nullptr) {
    cout << "This pointer doesn't point to anything yet.\n";
  }

  return 0;
}
