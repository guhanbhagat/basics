// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


bool check(int x, vector<int> arr, vector<int> &sol ){
    set<int> as;
    int y = x;
    int setsize= 0;

    for(int i =0; i<= arr.size(); i++){
        sol[i] = y;
        as.insert(y);
        setsize++;
        if(setsize != as.size() ){
            return false;
        }
        if(i != arr.size()){
        y = arr[i]-y;
        if(y <= 0){
            return false;
        }
        }
    }
    return true;
}




int main() {
    (void) freopen("photo.in", "r", stdin);
    (void) freopen("photo.out", "w", stdout);
    int N;
    vector<int> arr;
    cin >> N;
    vector<int> sol(N); 
    for(int i = 0; i < N - 1; i++){
        int elem; cin >> elem;
        arr.push_back(elem);
    }
    for(int x = 1; x< arr[0]; x++){
        if(check(x,arr,sol)){
            break;
        }
    }
    for(int i = 0;i < N-1; i++){
        cout << sol[i] << " ";
    }
    cout << sol[N-1];
    return 0;
}
