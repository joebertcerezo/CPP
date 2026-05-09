#include <iostream>
#include <string>

using namespace std;

// This file covers Object-Oriented Programming (OOP) basics: Classes and
// Objects

class Car {
private:
  // Encapsulation: Keeping data safe and private
  string brand;
  int year;

public:
  // Constructor
  Car(string b, int y) {
    brand = b;
    year = y;
  }

  // Default Constructor
  Car() {
    brand = "Unknown";
    year = 0;
  }

  // Getter methods
  string getBrand() const { return brand; }
  int getYear() const { return year; }

  // Setter methods
  void setYear(int y) {
    if (y > 1885)
      year = y; // Basic validation
  }

  // Class Method
  void displayInfo() { cout << "Car: " << brand << " (" << year << ")\n"; }
};

int main() {
  // Creating objects
  Car myCar("Toyota", 2020);
  Car mysteryCar; // Uses default constructor

  myCar.displayInfo();
  mysteryCar.displayInfo();

  // Modifying using setter
  myCar.setYear(2022);
  cout << "Updated year: " << myCar.getYear() << "\n";

  return 0;
}
