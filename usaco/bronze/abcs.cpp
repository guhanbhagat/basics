// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class ints{
    public:
    int A;
    int B;
    int C;
    int AB;
    int BC;
    int AC;
    int ABC;
    vector<int> numbers;

    void findvalues(){
        sort(numbers.begin(), numbers.end());
        A = numbers[0];
        B = numbers[1];
        ABC = numbers[6];
        BC = numbers[5];
        C = BC - B;
        AC = A+ C;
        AB = ABC - C;
    }
};



int main() {
    ints input;
    for (int i =0; i<7; i++){
        int in;
        cin >> in;
        input.numbers.push_back(in);
    }
    input.findvalues();
    cout << input.A << " " << input.B << " " << input.C << endl;
}
