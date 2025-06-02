#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;


int find2ndmax(vector<int> distances){
    int maxdist = *max_element(distances.begin(), distances.end());
    for (int i = 0; i < distances.size(); i++){
        if (distances[i] == maxdist){
            distances[i] = 0;
            break;
        }
    }
    int nextmax = *max_element(distances.begin(), distances.end());
    return nextmax;
}

int process(vector<int> distances, string stalls, int mindistance){
    int maxdist = *max_element(distances.begin(), distances.end());
    int nextmax = find2ndmax(distances);
    if(stalls[0] == '0' && stalls[stalls.size()-1] == '0' && distances[0]-1 >= mindistance && distances[distances.size()-1] >= mindistance){
        return mindistance;
    }
    if((maxdist-2)/3 >= mindistance){
        return mindistance;
    }
    if(stalls[0] == '0'&& distances[0]-1 >= mindistance && (maxdist-1)/2 >= mindistance){
        mindistance = min(mindistance, maxdist / 2);
        return mindistance;
    }
    if(stalls[stalls.size()-1] == '0' && distances[distances.size()-1] >= mindistance && (maxdist-1)/2 >= mindistance){
        return mindistance;
    }
    if((nextmax-1)/2 >= mindistance){
        return mindistance;
    }
    int mindistance1 = ceil((maxdist-2)/3.0);
    int mindistance2 = ceil((nextmax-1)/2.0);
    int mindistance3 = min(distances[0], distances[distances.size()-1]) - 1;
    int mindistance4 = min(distances[0] - 1, (maxdist-1)/2);
    int mindistance5 = min(distances[distances.size()-1] - 1, (maxdist-1)/2);
    return max(mindistance1, max(mindistance2, max(mindistance3, max(mindistance4, mindistance5))));
}

bool checknumofzeros(string stalls){
    for (char i : stalls){
        if (i == '1'){
            return false;
        }
    }
    return true;
}


vector<int> calculateDistances(string stalls){
    int distance = 1;
    vector<int> distances;
    for (int i = 0; i< stalls.size(); i++){
        if(stalls[i] == '1'){
            distances.push_back(distance);
            distance = 1;
        }
        if(stalls[i] == '0'){
            distance++;
        }
    }
    distances.push_back(distance);
    return distances;

}

int main() {
    int N;
    cin >> N;
    string stalls;
    cin >> stalls;
    if (checknumofzeros(stalls)){
        cout << N-1 << endl;
        return 0;
    }
    vector<int> distances = calculateDistances(stalls);
    auto begin = distances.begin();
    auto end = distances.end();
    begin ++;
    end --;
    int mindist = *min_element(begin, end);
    cout << process(distances, stalls, mindist) << endl;
}