// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    (void)freopen("word.in", "r", stdin);
    (void)freopen("word.out","w", stdout);
	int N, k;
    cin >> N >>k;
    vector<string> words(N);
    for (int i = 0; i<N; i++){
        cin >> words[i];
    }
    vector<string> result;
    int numLines = 0;
    int charsLeft = k;
    for(string word : words){
        if (word.size() <= charsLeft){
            if (charsLeft == k){
                numLines++;
                result.push_back(string(""));
            }
            else{
                result[numLines-1].append(" ");
            }
            (result[numLines-1]).append(word);
            charsLeft -= word.size();
        }
        else{
            result.push_back(word);
            numLines ++;
            charsLeft = k-word.size();
        }
    }
    for (int i=0;i<numLines;i++){
        cout << result[i] << endl;
    }
}
