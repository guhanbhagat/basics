/* Problem 2: Awkward Digits [Brian Dean]

Bessie the cow is just learning how to convert numbers between different
bases, but she keeps making errors since she cannot easily hold a pen
between her two front hooves.  

Whenever Bessie converts a number to a new base and writes down the result,
she always writes one of the digits wrong.  For example, if she converts
the number 14 into binary (i.e., base 2), the correct result should be
"1110", but she might instead write down "0110" or "1111".  Bessie never
accidentally adds or deletes digits, so she might write down a number with
a leading digit of "0" if this is the digit she gets wrong.

Given Bessie's output when converting a number N into base 2 and base 3,
please determine the correct original value of N (in base 10). You can
assume N is at most 1 billion, and that there is a unique solution for N.

Please feel welcome to consult any on-line reference you wish regarding
base-2 and base-3 numbers, if these concepts are new to you.

PROBLEM NAME: digits

INPUT FORMAT:

* Line 1: The base-2 representation of N, with one digit written
        incorrectly.

* Line 2: The base-3 representation of N, with one digit written
        incorrectly.

SAMPLE INPUT (file digits.in):

1010
212

INPUT DETAILS:

When Bessie incorrectly converts N into base 2, she writes down
"1010".  When she incorrectly converts N into base 3, she writes down "212".

OUTPUT FORMAT:

* Line 1: The correct value of N.

SAMPLE OUTPUT (file digits.out):

14

OUTPUT DETAILS:

The correct value of N is 14 ("1110" in base 2, "112" in base 3).
  */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int toDecimal(string num, int base) {
  int decimal = 0;
  int power = 0;
  for (int i = num.length() - 1; i >= 0; i--) {
    decimal += stoi(string(1, num[i])) * pow(base, power);
    power++;
  }
  return decimal ;
}

string toBase(int num, int base){
  string result = "";
  while (num > 0) {
    int val = num % base;
    result = to_string(val) + result;
    num = (num-val)/base;
  }
  return result;
}


int main(){
  string binary, ternary;
  cin >> binary >> ternary;
  int decimal = 0;
  for (int i = 0; i < binary.length(); i++){
    string temp = binary;
    temp[i] = (binary[i] == '0') ? '1' : '0';
    int tempDecimal = toDecimal(temp, 2);
    for (int j = 0; j < ternary.length(); j++){
      string temp2 = ternary;
      for (int bunbun = 0; bunbun < 3; bunbun++){
        temp2[j] = to_string((stoi(string(1, ternary[j])) + bunbun) % 3)[0];
        int tempDecimal2 = toDecimal(temp2, 3);
        if (tempDecimal2 == tempDecimal){
          decimal = tempDecimal;
          cout << decimal << endl;
          return 0;
        }
      }
      
    }
  }
}
