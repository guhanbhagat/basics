// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int solution(int N, set<int> set1, set<int> set2){
    set<int> intersect;
    set_intersection(set1.begin(), set1.end(),set2.begin(), set2.end(), inserter(intersect,intersect.begin()));
    int count = intersect.size();
    //cout << count << endl;
    return count*(2*N-count);
}



int main() {
    int N,M;
    cin >> N >>M;
    vector<vector<int>> result(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j =0; j <= i; j++ ){
            char c; cin >> c;
            if(c == 'D'){
                result[i][j] = c;
                result[j][i] = c;
            }else if(c == 'W'){
                result[i][j] =c;
                result[j][i] = 'L';
            }else if(c == 'L'){
                result[i][j] = c;
                result[j][i] = 'W';
            }
        }
    }
    for(int i = 0; i< M-1; i++){
        int sym1,sym2;
        cin >> sym1 >> sym2;
        sym1--;
        sym2--;
        set<int> set1;
        set<int> set2;
        for(int j = 0; j< N; j++){
            if(result[sym1][j] == 'L'){set1.insert(j);}
            if(result[sym2][j] == 'L'){set2.insert(j);}
        }
        int sol = solution( N, set1, set2);
        cout << sol << endl;
    }
    int sym1,sym2;
    cin >> sym1 >> sym2;
    sym1--;
    sym2--;
    set<int> set1;
    set<int> set2;
    for(int j = 0; j< N; j++){
        if(result[sym1][j] == 'L'){set1.insert(j);}
        if(result[sym2][j] == 'L'){set2.insert(j);}
    }
    int sol = solution( N, set1, set2);
    cout << sol;
}

