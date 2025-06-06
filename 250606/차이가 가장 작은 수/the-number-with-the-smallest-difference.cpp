#include <iostream>
#include <set>
#include <limits.h>

using namespace std;

int n, m;
int arr[100000];

int main() {

    cin >> n >> m;
    set<int> s;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int x = arr[i];
        set<int>::iterator it;
        it = s.upper_bound(x - m);
        if (it != s.begin()){
            it--;
            ans = min(ans,abs(x - *it));
        }
    }
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}
