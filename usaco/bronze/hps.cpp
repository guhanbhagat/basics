// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class hPS{
    public:
    vector<vector<int>> games;
    int numGames;
    vector<map<int, int>> numsToSymbols = {{{1,1},{2,2},{3,3}}, {{1,1}, {2,3}, {3,2}}}; // in symbol 1<2<3<1
    int gamesWon1;
    int gamesWon2;

    void calculategames(){
        for(int i = 0; i<2; i++){
            int count = 0;
            for(int j = 0; j<numGames; j++){
                int play1 = games[j][0];
                int play2 = games[j][1];
                int choice1 = numsToSymbols[i][play1];
                int choice2 = numsToSymbols[i][play2];
                if((choice1 > choice2 && false == (choice1 == 3 && choice2 == 1) || (choice1 == 1 && choice2 == 3)) ){
                    count ++;

                }
            }
            if (i == 0){
                gamesWon1 = count;
            }
            else{
                gamesWon2 = count;
            }

        }
    }
    
};









int main() {
    (void)freopen("hps.in", "r", stdin);
    (void)freopen("hps.out", "w", stdout);
    hPS HPS;
    cin >> HPS.numGames;
    for(int i = 0; i<HPS.numGames; i++){
        HPS.games.push_back({0,0});
    }
    for(int i = 0; i<HPS.numGames; i++){
        for(int j = 0; j<2; j++){
            cin >> HPS.games[i][j];
        }
    }
    HPS.calculategames();
    cout << max(HPS.gamesWon1, HPS.gamesWon2);
}
