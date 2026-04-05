#include <iostream>
#include <string>

using namespace std;

// This file covers advanced pointer and reference concepts
// Topics: pointer arithmetic, const pointers, pointers to pointers,
// arrays & pointers, function pointers, and common pitfalls

// ============= POINTER ARITHMETIC =============
void pointerArithmetic() {
  cout << "\n=== POINTER ARITHMETIC ===\n";

  int arr[] = {10, 20, 30, 40, 50};
  int *ptr = arr;

  // Pointer arithmetic: incrementing moves to next element
  cout << "arr[0] via pointer: " << *ptr << "\n";
  ptr++;
  cout << "arr[1] via pointer: " << *ptr << "\n";

  // Pointer arithmetic with arrays
  int *ptr2 = &arr[0];
  cout << "arr[3] using ptr2 + 3: " << *(ptr2 + 3) << "\n";
  cout << "Address difference: " << (ptr2 + 3) - ptr2 << " elements\n";
}

// ============= CONST POINTERS & POINTERS TO CONST =============
void constPointers() {
  cout << "\n=== CONST POINTERS ===\n";

  int x = 10;
  int y = 20;

  // 1. Pointer to const: can't modify the pointed-to value
  const int *ptr1 = &x;
  cout << "Pointer to const: " << *ptr1 << "\n";
  // *ptr1 = 15;  // ERROR: can't modify
  ptr1 = &y; // OK: can change what it points to
  cout << "Now points to: " << *ptr1 << "\n";

  // 2. Const pointer: can't change what it points to
  int *const ptr2 = &x;
  cout << "Const pointer: " << *ptr2 << "\n";
  *ptr2 = 15; // OK: can modify the value
  // ptr2 = &y;   // ERROR: can't change what it points to
  cout << "Modified value: " << *ptr2 << "\n";

  // 3. Const pointer to const: can't do either
  const int *const ptr3 = &x;
  // *ptr3 = 15;  // ERROR
  // ptr3 = &y;   // ERROR
  cout << "Const pointer to const: " << *ptr3 << "\n";
}

// ============= POINTER TO POINTER =============
void pointerToPointer() {
  cout << "\n=== POINTER TO POINTER ===\n";

  int value = 42;
  int *ptr = &value;   // pointer to int
  int **ptrPtr = &ptr; // pointer to pointer

  cout << "Value: " << value << "\n";
  cout << "Via ptr: " << *ptr << "\n";
  cout << "Via ptrPtr: " << **ptrPtr << "\n";

  cout << "Address of value: " << &value << "\n";
  cout << "Address of ptr: " << &ptr << "\n";
  cout << "Address stored in ptrPtr: " << *ptrPtr << "\n";

  // Modifying through pointer to pointer
  **ptrPtr = 100;
  cout << "After **ptrPtr = 100, value is: " << value << "\n";
}

// ============= ARRAYS AND POINTERS =============
void arraysAndPointers() {
  cout << "\n=== ARRAYS AND POINTERS ===\n";

  int arr[] = {10, 20, 30, 40, 50};

  // Arrays decay to pointers when needed
  int *ptr = arr; // equivalent to &arr[0]

  cout << "arr = " << arr << "\n";
  cout << "ptr = " << ptr << "\n";
  cout << "Both point to the same address\n";

  // Using pointer notation to access array elements
  cout << "arr[2] = " << arr[2] << "\n";
  cout << "*(ptr + 2) = " << *(ptr + 2) << "\n";
  cout << "2[arr] = " << 2 [arr] << "\n"; // Interesting: this works!

  // Pointer to an array (different from pointer to first element)
  int (*arrPtr)[5] = &arr; // pointer to array of 5 ints
  cout << "Via array pointer: " << (*arrPtr)[2] << "\n";
}

// ============= FUNCTION POINTERS =============
int add(int a, int b) { return a + b; }

int multiply(int a, int b) { return a * b; }

void functionPointers() {
  cout << "\n=== FUNCTION POINTERS ===\n";

  // Declare a function pointer
  int (*funcPtr)(int, int);

  // Point to the add function
  funcPtr = add;
  cout << "add(5, 3) = " << funcPtr(5, 3) << "\n";

  // Change to point to multiply
  funcPtr = multiply;
  cout << "multiply(5, 3) = " << funcPtr(5, 3) << "\n";

  // Function pointers are useful for callbacks
  cout << "Using function pointer directly: " << (*funcPtr)(4, 2) << "\n";
}

// ============= REFERENCES VS POINTERS =============
void referencesVsPointers() {
  cout << "\n=== REFERENCES VS POINTERS ===\n";

  int x = 10;

  // References
  int &ref = x; // Must be initialized, can't be null
  cout << "Reference initialized to x\n";
  // ref = nullptr;    // ERROR: can't do this
  // int &ref2;        // ERROR: reference must be initialized

  // Pointers
  int *ptr = nullptr; // Can be null
  ptr = &x;           // Can be changed

  cout << "Size of reference: " << sizeof(ref) << " bytes\n";
  cout << "Size of pointer: " << sizeof(ptr) << " bytes\n";

  cout << "Reference: no need to dereference, access like: " << ref << "\n";
  cout << "Pointer: need to dereference: " << *ptr << "\n";
}

// ============= DYNAMIC MEMORY & COMMON PITFALLS =============
void dynamicMemory() {
  cout << "\n=== DYNAMIC MEMORY ===\n";

  // Allocate memory on heap
  int *ptr = new int;
  *ptr = 42;
  cout << "Dynamically allocated int: " << *ptr << "\n";
  delete ptr; // Must free memory

  // Allocate array
  int *arr = new int[5];
  arr[0] = 100;
  cout << "Dynamically allocated array[0]: " << arr[0] << "\n";
  delete[] arr; // Note: delete[] for arrays

  // Common mistake: dangling pointer
  int *dangling = new int(50);
  delete dangling;
  // dangling now points to freed memory (dangling pointer)
  // cout << *dangling << "\n";  // UNDEFINED BEHAVIOR!
  dangling = nullptr; // Good practice after deleting
}

// ============= REFERENCES IN FUNCTION RETURNS =============
int &dangerousReturn(int &x) {
  // DO NOT return reference to local variable!
  // This is a common error:
  // int local = 5;
  // return local;  // UNDEFINED BEHAVIOR

  return x; // OK: returning reference to parameter
}

void referenceReturns() {
  cout << "\n=== REFERENCE RETURNS ===\n";

  int x = 100;
  int &ref = dangerousReturn(x);
  cout << "Reference returned from function: " << ref << "\n";

  ref = 200;
  cout << "After modifying through reference, x = " << x << "\n";
}

// ============= TIPS AND BEST PRACTICES =============
void bestPractices() {
  cout << "\n=== BEST PRACTICES ===\n";

  cout << "1. Use references when:\n";
  cout << "   - Function parameters that shouldn't be null\n";
  cout << "   - Return values (especially with STL containers)\n\n";

  cout << "2. Use pointers when:\n";
  cout << "   - Need to represent optional values (nullptr)\n";
  cout << "   - Doing pointer arithmetic\n";
  cout << "   - Need polymorphism (base class pointers)\n\n";

  cout << "3. Use const correctness:\n";
  int x = 10;
  const int *ptr1 = &x;       // Pointer to const
  int *const ptr2 = &x;       // Const pointer
  const int *const ptr3 = &x; // Both const
  cout << "   All three variants demonstrated above\n\n";

  cout << "4. Always avoid:\n";
  cout << "   - Dangling pointers (delete then use)\n";
  cout << "   - Memory leaks (allocate without delete)\n";
  cout << "   - Returning references to local variables\n";
}

int main() {
  pointerArithmetic();
  constPointers();
  pointerToPointer();
  arraysAndPointers();
  functionPointers();
  referencesVsPointers();
  dynamicMemory();
  referenceReturns();
  bestPractices();

  cout << "\n=== END OF ADVANCED POINTERS & REFERENCES ===\n";

  return 0;
}
