// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class socdist2 {
    public:
    vector<int> healthy;
    vector<int> sick;
    int N;
    int R;
    vector<vector<int>> groups;


    void buildHealthyAndSick(){
        for (int i = 0; i<N; i++){
            int x;
            int address;
            cin >> address >> x;
            if (x == 0){
                healthy.push_back(address);
            }
            else{
                sick.push_back(address);
            }
        }
        sort(healthy.begin(), healthy.end());
        sort(sick.begin(), sick.end());
    }

    void findR(){
        R = pow(10,6);
        for (auto i : sick){
            for (auto j : healthy){
                R = min(R, abs(i-j)-1);
            }
        }
    }

    void findgroups(){
        vector<int> group;
        for(int i = 0; i < sick.size(); i++){
            group.push_back(sick[i]);
            if(abs(sick[i]-sick[i+1]) <= R){
                continue;
            }
            groups.push_back(group);
            group = {};

        }
    }


    void print(){
        cout << N << endl;
        cout << "healthy : " << endl;
        for (int i = 0; i<healthy.size(); i++){
            cout << healthy[i] << endl;
        }
        cout << "sick :" << endl;
        for (int i = 0; i<sick.size(); i++){
            cout << sick[i] << endl;
        }
        cout << endl;
        cout << R << endl;

    }
};





int main() {
    (void)freopen("socdist2.in", "r", stdin);
    (void)freopen("socdist2.out", "w", stdout);
    socdist2 cowvid;
    cin >> cowvid.N;
    cowvid.buildHealthyAndSick();
    cowvid.findR();
    cowvid.findgroups();
    //cowvid.print();
    cout << cowvid.groups.size();
}
