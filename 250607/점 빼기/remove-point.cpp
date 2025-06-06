#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 100000;
int n, m;
int x[MAX_N], y[MAX_N];
int k[MAX_N];

int main() {

    cin >> n >> m;
    set<pair<int,int>> s;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        s.insert(make_pair(x[i],y[i]));
    }

    for (int i = 0; i < m; i++) {
        cin >> k[i];
        auto it = s.lower_bound(make_pair(k[i],1));
        if (it == s.end()) cout << -1 << " " << -1 << "\n";
        else{
            cout << it->first << " " << it->second << "\n";
            s.erase(*it);
        }
    }
    return 0;
}
