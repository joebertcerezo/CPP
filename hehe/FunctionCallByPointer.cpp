#include <iostream>
using namespace std;


int main(){
  int ref[] = {10, 20, 30, 40, 50};
  int *refPtr = ref;
  cout << ref << "\n";
  cout << &ref << "\n";
  
  cout << refPtr << "\n";
  cout << *refPtr << "\n";

  

  return 0;
}
