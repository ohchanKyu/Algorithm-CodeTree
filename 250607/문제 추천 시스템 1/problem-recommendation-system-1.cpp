#include <iostream>
#include <string>
#include <set>

using namespace std;

int n, m;
int P[100000], L[100000];

struct cmp_1 {
    bool operator()(const pair<int,int> &a,const pair<int,int> &b) const {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    };
};
struct cmp_2 {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};
int main() {

    cin >> n;
    set<pair<int,int>,cmp_1> s;
    set<pair<int,int>,cmp_2> s1;
    for (int i = 0; i < n; i++) {
        cin >> P[i] >> L[i];
        s.insert({ L[i],P[i]});
        s1.insert({ L[i], P[i]});
    }
    

    cin >> m;
    for (int i = 0; i < m; i++) {
        string command;
        cin >> command;
        if (command == "rc") {
            int x;
            cin >> x;
            if (x == 1){
                auto it = s.rbegin();
                cout << (*it).second << "\n";
            }else{
                auto it = s1.begin();
                cout << (*it).second << "\n";
            }
        } else if (command == "ad") {
            int p, l;
            cin >> p >> l;
            s.insert(make_pair(l,p));
            s1.insert({l,p});

        } else if (command == "sv") {
            int p, l;
            cin >> p >> l;
            s.erase(make_pair(l,p));
            s1.erase({l,p});
        }
    }

    // Please write your code here.

    return 0;
}
