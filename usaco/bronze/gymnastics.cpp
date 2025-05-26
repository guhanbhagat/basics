/*
In order to improve their physical fitness, the cows have taken up gymnastics! Farmer John designates his favorite cow Bessie to coach the N
 other cows and to assess their progress as they learn various gymnastic skills.
In each of K
 practice sessions (1≤K≤10
), Bessie ranks the N
 cows according to their performance (1≤N≤20
). Afterward, she is curious about the consistency in these rankings. A pair of two distinct cows is consistent if one cow did better than the other one in every practice session.

Help Bessie compute the total number of consistent pairs.

INPUT FORMAT (file gymnastics.in):
The first line of the input file contains two positive integers K
 and N
. The next K
 lines will each contain the integers 1…N
 in some order, indicating the rankings of the cows (cows are identified by the numbers 1…N
). If A
 appears before B
 in one of these lines, that means cow A
 did better than cow B
.
OUTPUT FORMAT (file gymnastics.out):
Output, on a single line, the number of consistent pairs.
SAMPLE INPUT:
3 4
4 1 2 3
4 1 3 2
4 2 1 3
SAMPLE OUTPUT:
4
The consistent pairs of cows are (1,4)
, (2,4)
, (3,4)
, and (1,3)
.
*/
#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, int>> make_pairs(int num){
    vector<pair<int, int>> pairs;
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            pair<int,int> pr(i+1,j+1);
            pairs.push_back(pr);
        }
    }
    return pairs;
}

int count_consistency( vector<vector<bool>> orderings) {
    int count = 0;
    for (auto order: orderings) {
        bool first = order[0];
        bool consistent = true;
        for (auto value: order) {
            if (value != first) {
                consistent = false;
                break;
            }            
        }
        if (consistent) {
            count++;
        }
    }
    return count;
}

vector<vector<bool>> make_orderings(vector<pair<int, int>> pairs, vector<vector<int>> orders){
    vector<vector<bool>> orderings;
    for( auto pair: pairs) {
        vector<bool> ordering = {};
        for (auto order: orders) {
            for (auto value: order ) {
                if (pair.first == value) {
                    ordering.push_back(true);
                    break;
                }
                if (pair.second == value) {
                    ordering.push_back(false);
                    break;
                }
            }
        }
        orderings.push_back(ordering);
    }
    return orderings;
}

int process(int num, vector<vector<int>> orders ){
    vector<pair<int, int>> pairs = make_pairs(num);
    vector<vector<bool>> orderings = make_orderings(pairs, orders);
    int count = count_consistency(orderings);
    return count;
}

int main() {
    //(void)freopen("gymnastics.in", "r", stdin);
    //(void)freopen("gymnastics.out", "w", stdout);
    int num, sessions;
    cin >> sessions >> num;
    vector<vector<int>> orders;
    for (int i = 0; i < sessions; i++){
        vector<int> order;
        for (int j = 0; j < num; j++){
            int temp;
            cin >> temp;
            order.push_back(temp);
        }
        orders.push_back(order);
    }
    cout << process(num, orders) << endl;
    return 0;
}
