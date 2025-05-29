// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    (void)freopen("notlast.in","r",stdin);
    (void)freopen("notlast.out","w",stdout);
    int numLines;
    cin >> numLines;
    vector<string> result;
    map<string, int> amounts = {{"Bessie", 0},{"Elsie",0},{"Henrietta",0},{"Daisy",0},{"Gertie",0},{"Annabelle",0},{"Maggie",0}};
    vector<string> names = {"Bessie", "Elsie", "Daisy","Gertie","Annabelle","Maggie","Henrietta"};
    for (int i = 0;i<numLines; i++){
        string name;
        int amount;
        cin >> name >> amount;
        amounts[name] += amount;
    }
    int minimum= 10000;
    for (int i = 0;i<names.size();i++){
        minimum = min(minimum, amounts[names[i]]);
    }
    int min2 = 100000;
    for (int i = 0;i<names.size();i++){
        if(amounts[names[i]] != minimum){
            min2 = min(min2, amounts[names[i]]);
        }
    }
    for (int i = 0;i<names.size();i++){
        if(amounts[names[i]] == min2){
            result.push_back(names[i]);
        }
    }
    if (result.size() == 1){
        cout << result[0] << endl;
    }
    else{
        cout << "Tie" << endl;
    }
    

}
