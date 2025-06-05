// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class milk{
    public:
    int X;
    int Y;
    int Z;
    int M;
    int a;
    int b;

    void chickenmgnuggettheorem(){
        if(X*Y-X-Y<M){
            Z = M;
        }
        else{
            a = M / X;
            for(int i = 0; i<=a; i++){
                b = (M-X*i) / Y;
                for(int j = 0; j<= b;j++){
                    Z = max(X*i +b*Y, Z);
                }
            } 
        }
    }
};


int main() {
    (void)freopen("pails.in", "r", stdin);
    (void)freopen("pails.out", "w", stdout);
    milk done;
    cin >> done.X >> done.Y >> done.M;
    done.chickenmgnuggettheorem();
    cout << done.Z << endl;
}
