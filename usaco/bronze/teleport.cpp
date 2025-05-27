// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
    (void)freopen("teleport.in", "r", stdin);
    (void)freopen("teleport.out","w", stdout);
    int a,b,x,y;
    cin >> a>>b>>x>>y;
    if (abs(a-x)+abs(b-y) <= abs(a-b)){
        cout << abs(a-x)+abs(b-y) << endl;
    }
    else if (abs(a-y)+abs(b-x) <= abs(a-b)) {
        cout << abs(a-y)+abs(b-x) << endl;
    }
    else{
        cout << abs(a-b) << endl;

    }
}
