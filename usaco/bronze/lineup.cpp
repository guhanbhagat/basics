// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    map<string, unsigned int> translate;
    vector<set<int>> pairs(8);
	vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    vector<int> nums(8);
    vector<string> res;
    int n; cin >> n;
    for(int i = 0; i < 8; i++){
        translate.insert({cows[i],i});
    }
    for(int i = 0; i<n; i++){
        string x, must, be,milked,beside, y;
        cin >> x >> must >> be >> milked >> beside >> y;
        pairs[translate[x]].insert(translate[y]);
        pairs[translate[y]].insert(translate[x]);
        nums[translate[x]]++;
        nums[translate[y]]++;
    }
    int i= 0;
    bool plus = false;
    while(res.size()<8){

        if(nums[i] == 3){
            i++;
            continue;
            
        }
        else if(nums[i] == 0){
            //cout<< i  << " 0 ";
            res.push_back(cows[i]);
            nums[i] = 3;

            if(plus){i = 0;}
            else{i++;}
          //  cout<< i << nums[i] << endl;
            
        }
        else if(nums[i] == 1){
            //cout<< i <<  " 1 ";
            res.push_back(cows[i]);
            set<int> j = pairs[i];
            j.erase(i);
            int k = *j.begin();
            pairs[k].erase(i);
            nums[i] = 3;
            i = k;
            //cout << i  << nums[i] << endl;
            nums[i]--;
            plus = true;
        }
        else if(nums[i] == 2){
            i++;
            continue;   
            
        }
    }
    for(int j = 0; j < 8; j++){
        cout << res[j] << endl;
    }
}
