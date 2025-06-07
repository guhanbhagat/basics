// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class lostcow{
    public:
    int x;
    int y;
    int n;
    int prev;
    int boundary;
    int distance;

    void findboundary(){
        prev = boundary;
        if( n % 2){
            boundary = x + pow(2, n-1);
        }
        else{
            boundary = x - pow(2,n-1);
        }
    }

    bool checky(){
        if((boundary <= y && y < x) || (boundary >=y && y >= x)){
            return true;
        }
        return false;
    }

    void process(){
        n = 1;
        while(1){
            findboundary();
            if(checky()){
                calculatedistance();
                break;
            }
            n++;
        }
    }
    void calculatedistance(){
        if ( y == x){
            distance = 0;
            cout << distance << endl;
            return;
        }
        distance = 3*pow(2, n-2) -2 + abs(y - prev);
        cout << distance << endl;
    }

};


int main() {
    (void)freopen("lostcow.in", "r", stdin);
    (void)freopen("lostcow.out", "w", stdout);
    lostcow bessie;
    cin >> bessie.x >> bessie.y;
    bessie.process();
}
