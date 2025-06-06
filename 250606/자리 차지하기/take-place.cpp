#include <iostream>
#include <set>
#include <queue>

using namespace std;

int n, m;
int a[100000];

int main() {
    
    cin >> n >> m;

    set<int> s;
    for(int i=1;i<=m;i++){
        s.insert(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        
        cin >> a[i];
        auto it = s.upper_bound(a[i]);
        if (it == s.begin()) break;
        --it;
        s.erase(*it);
        ans += 1;
    }
    cout << ans;

    return 0;
}
