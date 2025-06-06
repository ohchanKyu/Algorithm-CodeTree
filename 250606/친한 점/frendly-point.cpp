#include <iostream>
#include <set>

using namespace std;

int n, m;
int x[100000], y[100000];
int qx[100000], qy[100000];

int main() {

    cin >> n >> m;
    set<pair<int,int>> set;

    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        set.insert(make_pair(x[i],y[i]));
    }
    for (int i = 0; i < m; i++){
        cin >> qx[i] >> qy[i];
        auto it = set.lower_bound(make_pair(qx[i],qy[i]));
        if (it == set.end()) cout << -1 << " " << -1 << "\n";
        else cout << it->first << " " << it->second << "\n";
    }
    return 0;
}
