#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
int arr1[100000];
int arr2[100000];

int main() {

    cin >> n;
    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        set.insert(arr1[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        if (set.find(arr2[i]) != set.end()) cout << 1 << " ";
        else cout << 0 << " ";
    }
    return 0;
}
