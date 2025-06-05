#include <iostream>
#include <unordered_set>

using namespace std;

int n;
int m;
int a[100000];
int b[100000];

int main() {
    
    cin >> n;
    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        set.insert(a[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (set.find(b[i]) != set.end()) cout << 1 << "\n";
        else cout << 0 << "\n";
    }


    return 0;
}
