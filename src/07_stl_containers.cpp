#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// This file covers the Standard Template Library (STL): Vectors, Maps, and
// Algorithms.

int main() {
  cout << "--- 1. std::vector (Dynamic Array) ---\n";
  vector<int> numbers = {1, 2, 3};
  numbers.push_back(4); // Add to end
  numbers.push_back(5);

  // Iterating with range-based for loop
  for (int num : numbers) {
    cout << num << " ";
  }
  cout << "\n";

  cout << "\n--- 2. std::map (Key-Value Dictionary) ---\n";
  map<string, int> ages;
  ages["Alice"] = 25;
  ages["Bob"] = 30;

  // Iterating through a map
  for (const auto &pair : ages) {
    cout << pair.first << " is " << pair.second << " years old.\n";
  }

  cout << "\n--- 3. Algorithms (Sorting) ---\n";
  vector<int> randomNums = {5, 2, 9, 1, 6};
  sort(randomNums.begin(), randomNums.end()); // Requires <algorithm>

  cout << "Sorted numbers: ";
  for (int n : randomNums) {
    cout << n << " ";
  }
  cout << "\n";

  return 0;
}
