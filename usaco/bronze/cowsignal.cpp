// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
using namespace std;

string magnify(string s, int factor){
    string result;
    for (char ch:s){
        for (int i = 0;i<factor;i++){
            result.push_back(ch);
        }
    }
    return result;
}

vector<string> process(int rows, int factor, vector<string> signal){
    vector <string> result;
    for (int i=0;i<rows;i++){
        for (int j = 0; j < factor; j++){
            result.push_back(magnify(signal[i],factor));
        }
    }
    return result;
}

int main() {
    (void)freopen("cowsignal.in", "r", stdin);
    (void)freopen("cowsignal.out", "w", stdout);
    int rows, cols, factor;
    cin >> rows >> cols >> factor;
    vector<string> signal(rows);
    for (int i =0; i<rows;i++){
        cin >> signal[i];
    }
    vector<string> result = process(rows,factor,signal);
    for (int i =0; i<rows*factor;i++){
        cout << result[i] << endl;
    }
}



