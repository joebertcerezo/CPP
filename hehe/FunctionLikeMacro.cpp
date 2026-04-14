#include <iostream>
using namespace std;

#define MIN(a, b) (a > b ? b : a)

int main(){
  int i, j;
  i = 10;
  j = 30;

  cout << "Minimum between " << j << " and " << i << " is " << MIN(i, j);
  
  return 0;
}
