// Source: https://usaco.guide/general/io

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class milk{
    public:
    int N;
    vector<string> animals;
    vector<int> nums;
    vector<vector<string>> chars;
    int maxoverlap = 0;

    void findmaxoverlap(){
        sort(chars.begin(), chars.end(), []( vector<string>a,  vector<string>b){return a.size() > b.size();});
        for (int i = 0; i < N; i++){
            vector<string> chr = chars[i];
            for (int j = i+1; j<N; j++){
                vector<string> overlap = {};
                for(int k = 0; k < max(chars[i].size(), chars[j].size()); k++){
                    if(find(chars[j].begin(), chars[j].end(),chr[k]) != chars[j].end()){
                        overlap.push_back(chr[k]);
                        
                    }
                }
                maxoverlap = max(maxoverlap, int(overlap.size()));
            }

        }
    }
};


int main() {
    (void)freopen("guess.in", "r", stdin);
    (void)freopen("guess.out", "w", stdout);
    milk done;
    cin >> done.N;
    for(int i = 0; i < done.N; i++){
        string animal;
        cin >> animal;
        done.animals.push_back(animal);
        int num;
        cin >> num;
        done.nums.push_back(num);
        done.chars.push_back({});
        for(int j = 0; j<num; j++){
            string characteristic;
            cin >> characteristic;
            done.chars[i].push_back(characteristic);
        }
    }
    done.findmaxoverlap();
    cout << done.maxoverlap + 1 << endl;

}
