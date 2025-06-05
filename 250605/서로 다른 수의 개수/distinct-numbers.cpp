#include <iostream>
#include <unordered_set>

using namespace std;

const int MAX_N = 100000;
int n;
int arr[MAX_N];

int main() {

    cin >> n;
    unordered_set<int> set;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        set.insert(arr[i]);
    }
    cout << set.size();
    return 0;
}
