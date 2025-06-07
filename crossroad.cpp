// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class cross{
    public:
    int N;
    map<int, vector<int>> roads;
    int crossings;

    void findcrossings(){
        for(int i = 1; i<=10; i++){
            if(roads.find(i) != roads.end()){
                for(int j = 0; j < roads[i].size()-1;j++){
                    if (roads[i][j] != roads[i][j+1]){
                        crossings++;
                    }
                }
            }
        }
    }
};

int main() {
    (void)freopen("crossroad.in", "r", stdin);
    (void)freopen("crossroad.out", "w", stdout);
    cross road;
    cin >> road.N;
    for(int i = 0; i<road.N; i++){
        int j,k;
        cin >> j >> k;
        if(road.roads.find(j)  != road.roads.end() ){
            road.roads[j].push_back(k);
        }
        else{
            road.roads.insert({j, {k}});
        }

    }
    road.findcrossings();
    cout << road.crossings << endl;
}
