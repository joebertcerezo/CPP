#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// This file covers Lambda Expressions and generic Templates.

// 1. Function Template
template <typename T> T getMax(T a, T b) { return (a > b) ? a : b; }

int main() {
  cout << "--- Templates ---\n";
  cout << "Max Int: " << getMax<int>(5, 10) << "\n";
  cout << "Max Double: " << getMax<double>(3.14, 2.71) << "\n";

  cout << "\n--- Lambda Expressions ---\n";
  // Lambda syntax: [captures](parameters) -> return_type { body }
  auto add = [](int a, int b) { return a + b; };
  cout << "Lambda Add (3, 4): " << add(3, 4) << "\n";

  vector<int> vec = {1, 2, 3, 4, 5};
  int multiplier = 10;

  cout << "Values multiplied by 10: ";
  // Using lambda with standard algorithm and capturing external variable
  for_each(vec.begin(), vec.end(),
           [multiplier](int n) { cout << n * multiplier << " "; });
  cout << "\n";

  return 0;
}
