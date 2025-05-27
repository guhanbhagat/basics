// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

vector<int> mix(vector<int> amounts, vector<int> capacities, int offset){
    int first =( 0 + offset) % 3;
    int second = (1 + offset) % 3;
    if (amounts[(first) % 3 ] + amounts[second] >= capacities[second]){
        amounts[first] = amounts[first] + amounts[second] - capacities[second];
        amounts[second] = capacities[second];
    }
    else{
        amounts[second] = amounts[first]+amounts[second];
        amounts[first] = 0;
    }
    return amounts;
}
int main() {
    (void)freopen("mixmilk.in", "r", stdin);
    (void)freopen("mixmilk.out", "w", stdout);
    int capacity1, capacity2, capacity3, amount1, amount2, amount3;
	cin >> capacity1 >> amount1 >> capacity2 >> amount2 >> capacity3 >> amount3;
    vector<int> amounts = {amount1, amount2, amount3};
    vector<int> capacities = {capacity1, capacity2, capacity3};
    for (int i = 0; i<100; i++){
        amounts = mix(amounts, capacities, i);
    }
    cout << amounts[0] << endl;
    cout << amounts[1] << endl;
    cout << amounts[2] << endl;
}
