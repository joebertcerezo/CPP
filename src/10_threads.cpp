#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

// This file covers Basic Multithreading (Advanced C++ Threading).

void workerFunction(int id) {
  cout << "Thread " << id << " started.\n";
  // Simulate some work
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "Thread " << id << " finished.\n";
}

int main() {
  cout << "--- Multithreading Basics ---\n";
  cout << "Main thread starting.\n";

  // Create threads
  thread t1(workerFunction, 1);
  thread t2(workerFunction, 2);

  // Wait for threads to finish their execution before proceeding
  // If we don't join or detach, the program will terminate abruptly.
  t1.join();
  t2.join();

  cout << "Main thread finished.\n";
  return 0;
}
