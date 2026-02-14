// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void flip(int n, vector<vector<bool>> &grid, int row, int col ){
    for(int i = 0; i<=row; i++){
        for(int j =0; j<= col; j++){
            grid[i][j] = !grid[i][j];
        }
    }
}

pair<int, int> findcoords(int n, vector<vector<bool>> grid){
    for(int i = n-1; i>= 0; i--){
        for(int j= n-1; j>= 0; j--){
            if(grid[i][j]){return make_pair(i,j);}
        }
    }
    return make_pair(n,n);
}



int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n; cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n));
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            char m;
            cin >> m;
            grid[i][j] = (m == '1');
        }
    }
    int count = 0;
    while(true){
        pair<int,int> coords = findcoords(n, grid);
        pair<int,int> end = make_pair(n,n);
        if(coords == end){
            break;
        }
        flip(n,grid, coords.first, coords.second);
        count++;
    }
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            int m;
            m = grid[i][j];
        }
    }
    cout << count;
}