// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class brigade{
    public:
    int deltax;
    int deltay;
    int distance;

    void finddistance(){
        distance = deltax +deltay -1;
    }
};


int main() {
    (void)freopen("buckets.in", "r", stdin);
    (void)freopen("buckets.out", "w", stdout);
    brigade buckets;
    int x1,x2,y1,y2,x3,y3;
    for(int i = 0; i<10; i++){
        string str;
        cin >> str;
        if(str != ".........."){
            for(int j = 0; j<10; j++){
                if(str[j] == 'B'){
                    y1 = i;
                    x1 = j;
                }
                if(str[j] == 'L'){
                    y2 = i;
                    x2 = j;
                }
                if(str[j] =='R'){
                    y3 = i;
                    x3 = j;
                }
            }
        }
    }
    buckets.deltax = abs(x1 - x2);
    buckets.deltay = abs(y1-y2);
    buckets.finddistance();
    bool a = y1 == y2 && y2 == y3;
    bool b = x1<x3 && x3< x2;
    bool c = x2 < x3 && x3<x1;
    bool d = x1 == x3 && x3 == x2;
    bool e = y1<y3 && y3<y2;
    bool f = y2 < y3 && y3 < y1;
    if((a && (b|| c)) || (d && ((e) || (f )))){
        cout << buckets.distance + 2 << endl;
        return 0;
    }
    cout << buckets.distance << endl;
}
