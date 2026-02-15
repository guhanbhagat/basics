// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n; cin >> n;
    int count = 0;
    int finalcount = 0;
    vector<vector<int>> changes(100, vector<int>(3, 0));
    map<string, int> translate = {{"Bessie",0}, {"Elsie", 1}, {"Mildred", 2}};
    for(int i = 0; i<n; i++){
        int a,b, c;
        string s;
        cin >> a >> s >> c;
        b = translate[s];
        changes[a-1][b] = c;
    }
    vector<vector<int>> amounts(1, vector<int>(3,7)); 
    for(auto vect:changes){
        if (vect[0] != 0){
            amounts.push_back({amounts[count][0] + vect[0],amounts[count][1]+ vect[1], amounts[count][2] + vect[2]});
            count++;
        }
        else if (vect[1] != 0){
            amounts.push_back({amounts[count][0] + vect[0],amounts[count][1]+ vect[1], amounts[count][2] + vect[2]});
            count++;
        }
        else if (vect[2] != 0){
            amounts.push_back({amounts[count][0] + vect[0],amounts[count][1]+ vect[1], amounts[count][2] + vect[2]});
            count++;
        }
        
    }
    string prev;
    if(amounts[0][0] > max(amounts[0][1], amounts[0][2])){
        prev = "0";
    }
    if(amounts[0][1] > max(amounts[0][0], amounts[0][2])){
        prev = "1";
    }
    if(amounts[0][2] > max(amounts[0][1], amounts[0][0])){
        prev = "2";
    }
    if(amounts[0][0] == amounts[0][1] && amounts[0][0] > amounts[0][2]){
        prev = "01";
    }
    if(amounts[0][2] == amounts[0][1] && amounts[0][2] > amounts[0][0]){
        prev = "12";
    }
    if(amounts[0][0] == amounts[0][2] && amounts[0][0] > amounts[0][1]){
        prev = "02";
    }
    if(amounts[0][0] ==amounts[0][2] && amounts[0][0] == amounts[0][1]){
        prev= "012";
    }
    string max;
    for(auto i = 1; i<= n; i++ ){
        if(amounts[i][0] > std::max(amounts[i][1], amounts[i][2])){
            max = "0";
        }
        if(amounts[i][1] > std::max(amounts[i][0], amounts[i][2])){
            max = "1";
        }
        if(amounts[i][2] > std::max(amounts[i][1], amounts[i][0])){
            max = "2";
        }
        if(amounts[i][0] == amounts[i][1] && amounts[i][0] > amounts[i][2]){
            max = "01";
        }
        if(amounts[i][2] == amounts[i][1] && amounts[i][2] > amounts[i][0]){
            max = "12";
        }
        if(amounts[i][0] == amounts[i][2] && amounts[i][0] > amounts[i][1]){
            max = "02";
        }
        if(amounts[i][0] ==amounts[i][2] && amounts[i][0] == amounts[i][1]){
            max= "012";
        }
        if(max != prev){
            finalcount++;
            prev = max;
        }
    }
    for(int i = 0; i<=n; i++){
        for (int j = 0; j<3; j++){
          //  cout << amounts[i][j] << " ";
        }
        //cout << endl;
    }
    cout << finalcount ;
}
