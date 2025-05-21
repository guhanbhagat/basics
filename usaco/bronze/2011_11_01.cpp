#include <iostream>
#include <cassert>
using namespace std;

int calculateTime(int d, int h, int m);
bool tests();

int main() { 
  if (tests()) {
    cout << "Success" << endl;
  }
}

bool tests() {
  assert( calculateTime(11,11,11) == 0 );
  assert( calculateTime(11,11,12) == 1 );
  assert( calculateTime(11,12,12) == 61 );
  assert( calculateTime(12,11,11) == 24*60 );
  assert( calculateTime(12,1,1) == 24*60-10*60-10 );
  return true;
}

int calculateTime(int d, int h, int m) {
  return ((d-11)*24*60) + ((h-11)*60) + (m-11);
}
