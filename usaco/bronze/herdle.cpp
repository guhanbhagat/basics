// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class herdle{
    public:
    vector<char> correct;
    vector<char> guess;
    vector<int> rm;
    int green = 0;
    int yellow = 0;


    void findgreen(){
        for (int i = 0; i<9; i++){ 
            if(correct[i] == guess[i]){
                green++;
                rm.push_back(i);
            }
        }
    }

    void removegreen(){
        sort(rm.begin(), rm.end(), greater<int>());
        for(auto i : rm){
            correct.erase(correct.begin() + i);
            guess.erase(guess.begin() + i);
        }
    }

    void print() {
        cout << "Correct::\t";
        for (auto c : correct) {
            cout << c << ":";
        }
        cout << endl;
        cout << "Guess::\t";
        for (auto c : guess) {
            cout << c << ":";
        }
        cout << endl;
    }

    void findyellow(){
        for(int i = 0; i< correct.size(); i++){
            if(find(guess.begin(), guess.end(), correct[i]) != guess.end() ){
                yellow++;
                guess.erase(find(guess.begin(), guess.end(), correct[i]));
            }
        }
    }
};

int main() {
    herdle game;
    for (int i = 0; i<3; i++){
        string temp;
        cin >> temp;
        char t = temp[0];
        game.correct.push_back(t);
        t = temp[1];
        game.correct.push_back(t);
        t = temp[2];
        game.correct.push_back(t);
    }
    for (int i = 0; i<3; i++){
        string temp;
        cin >> temp;
        char t = temp[0];
        game.guess.push_back(t);
        t = temp[1];
        game.guess.push_back(t);
        t = temp[2];
        game.guess.push_back(t);
    }
    game.findgreen();
    cout << game.green << endl;
    game.removegreen();
    game.findyellow();
    cout << game.yellow << endl;
}
