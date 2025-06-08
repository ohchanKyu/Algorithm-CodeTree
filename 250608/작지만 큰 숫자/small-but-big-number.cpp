#include <iostream>
#include <set>

using namespace std;

int n, m;

int main() {
    
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        auto it = s.upper_bound(q);
        if (it == s.begin()) cout << -1 << "\n";
        else{
            it--;
            cout << *it << "\n";
            s.erase(it);
        }
    }
    return 0;
}
