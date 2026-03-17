#include <iostream>

using namespace std;

// This file covers function declarations, definitions, and passing parameters.

// 1. Simple Function
void greet() { cout << "Hello from a function!\n"; }

// 2. Function with return value and parameters (Pass by Value)
int add(int a, int b) { return a + b; }

// 3. Pass by Reference
// Notice the '&' - we are modifying the actual variable passed in.
void increment(int &num) { num++; }

// 4. Default Parameters
void printMessage(string msg = "Default Message") { cout << msg << "\n"; }

int main() {
  greet();

  int sum = add(5, 7);
  cout << "5 + 7 = " << sum << "\n";

  int value = 10;
  cout << "Before increment: " << value << "\n";
  increment(value);
  cout << "After increment: " << value << "\n";

  printMessage();
  printMessage("Custom Message");

  return 0;
}
