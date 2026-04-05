#include <iostream>
#include "maTry.h"

using namespace std;

// This file covers pointers and references, a core concept in C++.

void passByValue(int x);
void passByReference(int &x);
void passByPointer(int *x);

int main() {
  int num1 = 1;
  int &tryRef = num1;
  int *pp = &tryRef;

  cout << tryRef << "\n";
  cout << &tryRef << "\n";

  cout << "\n";
  cout << pp << "\n";
  cout << *pp << "\n";


  cout << "\n\n--- Pointers & References ---\n";

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

  int a = 5;
  cout << "a is 5 \n";

  cout << "passByValue(a)\n";
  passByValue(a);
  cout << "new value of a is " << a << "\n";

  cout << "passByReference(a)\n";
  passByReference(a);
  cout << "new value of a is " << a << "\n";

  cout << "passByPointer(a)\n";
  passByPointer(&a);
  cout << "new value of a is " << a << "\n";
  printMe();

  return 0;
}

void passByValue(int x){
  x = 10;
}

void passByReference(int &x){
  x = 15;
}

void passByPointer(int *x){
  *x = 20;
}
