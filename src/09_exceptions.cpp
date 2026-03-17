#include <iostream>
#include <stdexcept>

using namespace std;

// This file covers Exception Handling.

double divide(int a, int b) {
  if (b == 0) {
    throw runtime_error("Division by zero error");
  }
  return static_cast<double>(a) / b;
}

int main() {
  int numer = 10;
  int denom = 0;

  cout << "--- Exception Handling ---\n";

  try {
    // Attempting risky operation
    double result = divide(numer, denom);
    cout << "Result: " << result << "\n"; // Won't execute if exception thrown
  } catch (const runtime_error &e) {
    // Catching specific standard exceptions
    cout << "Caught a runtime error: " << e.what() << "\n";
  } catch (...) {
    // Catch-all block for any other type of exception
    cout << "Caught an unknown exception.\n";
  }

  cout << "Program continues execution after try-catch block.\n";

  return 0;
}
