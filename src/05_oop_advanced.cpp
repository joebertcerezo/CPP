#include <iostream>
#include <string>

using namespace std;

// This file covers Inheritance, Polymorphism, and Virtual Functions.

// Base Class
class Animal {
public:
  // Virtual function enables overriding in derived classes
  virtual void makeSound() const { cout << "Some generic animal sound\n"; }

  // Virtual destructor (import for safe polymorphic deletion)
  virtual ~Animal() {}
};

// Derived Class
class Dog : public Animal {
public:
  // Overriding base class function
  void makeSound() const override { cout << "Woof! Woof!\n"; }
};

// Derived Class
class Cat : public Animal {
public:
  void makeSound() const override { cout << "Meow!\n"; }
};

int main() {
  Animal genericAnimal;
  Dog myDog;
  Cat myCat;

  cout << "Standard calls:\n";
  genericAnimal.makeSound();
  myDog.makeSound();
  myCat.makeSound();

  cout << "\nPolymorphism in action:\n";
  // Using base class pointers to point to derived class objects
  Animal *ptr1 = new Dog();
  Animal *ptr2 = new Cat();

  ptr1->makeSound(); // Calls Dog's makeSound()
  ptr2->makeSound(); // Calls Cat's makeSound()

  delete ptr1;
  delete ptr2;

  return 0;
}
