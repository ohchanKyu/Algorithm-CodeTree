#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_N = 100000;

int n, m;
int arr[MAX_N];
int nums[MAX_N];

int main() {
    
    cin >> n >> m;
    unordered_map<int,int> numMap;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        numMap[arr[i]] += 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
        cout << numMap[nums[i]] << " ";
    }

    return 0;
}
