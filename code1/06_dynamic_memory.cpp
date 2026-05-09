#include <iostream>
#include <memory> // Required for smart pointers

using namespace std;

// This file covers manual dynamic memory and modern Smart Pointers.

class Entity {
public:
  Entity() { cout << "Entity Created!\n"; }
  ~Entity() { cout << "Entity Destroyed!\n"; }
  void print() { cout << "Printing from Entity\n"; }
};

int main() {
  cout << "--- 1. Raw Pointers (Manual Memory Management) ---\n";
  // Allocating memory dynamically
  int *val = new int;
  *val = 42;
  cout << "Value: " << *val << "\n";

  // Must remember to delete to avoid memory leaks
  delete val;

  // Arrays
  int *arr = new int[5]; // Allocate array
  delete[] arr;          // Delete array

  cout << "\n--- 2. Smart Pointers (Modern C++) ---\n";
  // unique_ptr: Scoped pointer. Deleted automatically when out of scope.
  {
    unique_ptr<Entity> entity = make_unique<Entity>();
    entity->print();
    // Automatically destroyed here!
  }

  cout << "\n--- 3. Shared Pointers ---\n";
  // shared_ptr: Uses reference counting. Freed when count hits 0.
  {
    shared_ptr<Entity> e1;
    {
      shared_ptr<Entity> sharedEntity = make_shared<Entity>();
      e1 = sharedEntity; // Ref count = 2
    } // Ref count = 1 (sharedEntity goes out of scope, but e1 still lives)
    cout << "Exiting inner scope. Entity still alive.\n";
  } // Ref count = 0 -> Entity destroyed here.

  return 0;
}
