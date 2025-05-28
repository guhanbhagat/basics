// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool seperate(int a,int b,int c,int d){
    if(b<c || a>d){
        return true;
    }
    return false;
}

int calculateInterval(int a,int b,int c,int d){
    return max(b,d) - min(a,c);
}

int main() {
    (void)freopen("paint.in", "r", stdin);
    (void)freopen("paint.out","w", stdout);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(seperate(a,b,c,d)){
        cout << abs(a-b) + abs(c-d);
    }
    else{
        cout << calculateInterval(a,b,c,d);
    }
}
