#include <iostream>
#include <set>

using namespace std;

int n, m;
int arr[100000];
int queries[100000];

int main() {

    cin >> n >> m;
    set<int> set;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        set.insert(arr[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
        auto it = set.lower_bound(queries[i]);
        if (it == set.end()) cout << -1 << "\n";
        else cout << *it << "\n";
    }

    return 0;
}
