// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class squarePasture{
    public:
    int x1;
    int x2;
    int x3;
    int x4;
    int y1;
    int y2;
    int y3;
    int y4;
    int x;
    int y;
    int length;

    void findMinXAndMinY(){
        this -> x = min(x1,min(x2,min(x3,x4)));
        this -> y = min(y1,min(y2,min(y3,y4)));
    }
    
    void findLength(){
        this->length = max(max(abs(x1-x),max(abs(x2-x), max(abs(x3-x), abs(x4-x)))),max(abs(y1-y), max(abs(y2-y), max(abs(y3-y), abs(y4-y)))) );
    }
};



int main() {
    (void)freopen("square.in", "r", stdin);
    (void)freopen("square.out", "w", stdout);
    squarePasture input;
    cin >> input.x1 >> input.y1 >> input.x2 >> input.y2 >> input.x3 >> input.y3 >> input.x4 >> input.y4;
    input.findMinXAndMinY();
    input.findLength();
    cout << (input.length) * (input.length) << endl;
}
