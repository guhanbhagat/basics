// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class WhereAmI{
    public:
    int numfarms;
    set<string> substrings;
    string mailboxes;
    int k;

    WhereAmI(int n, string mbox) {
        numfarms = n;
        mailboxes = mbox;
    }

    void print() {
        cout << "substrings" << endl;
        for ( auto s: substrings) {
            cout << s << ":";
        }
    }

    bool doesLenWork(int len) {
        int count = 0;
        for (int i = 0; i <= numfarms - len; i++) {
            count++;
            substrings.insert(mailboxes.substr(i, len));
            if (substrings.size() != count) {
                return false;
            }
        }
        //print();
        return true;
    }

    void findK(){
        int len = 1;
        while (len <= numfarms) {
            substrings.clear();
            if (doesLenWork(len)) {
                k = len;
                break;
            }
            len++;
        }
    }

};


int main() {
    (void)freopen("whereami.in", "r", stdin);
    (void)freopen("whereami.out", "w", stdout);
    int count;
    string mbox;
    cin >> count >> mbox;
    WhereAmI whereAmI(count, mbox);
    whereAmI.findK();
    cout << whereAmI.k << endl;
}
