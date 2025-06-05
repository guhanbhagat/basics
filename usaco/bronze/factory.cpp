// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class factory{
    public:
    int N;
    vector<int> input;
    vector<int> output;
    int ans = -1;

    void findAns(){
        int count = 0;
        for(int i = 1; i<=N; i++){
            if (find(input.begin(), input.end(), i) == input.end()){
                count ++;
                ans = i;
            }
        }
        if (count != 1){
            ans = -1;
        }
    }
};



int main() {
    (void)freopen("factory.in", "r", stdin);
    (void)freopen("factory.out", "w", stdout);
    factory milk;
    cin >> milk.N;
    for (int i =0; i<milk.N-1; i++){
        milk.input.push_back(0);
        milk.output.push_back(0);
    }
    for (int i =0; i<milk.N-1; i++){
        cin >> milk.input[i] >> milk.output[i];
    }
    milk.findAns();
    cout << milk.ans << endl;
}
