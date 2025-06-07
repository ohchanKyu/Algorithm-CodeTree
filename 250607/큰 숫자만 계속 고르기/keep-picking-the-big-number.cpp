#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[100000];

int main() {

    cin >> n >> m;

    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        q.push(arr[i]);
    }
    for(int i=0;i<m;i++){
        int target = q.top() - 1;
        q.pop();
        q.push(target);
    }
    cout << q.top();
    return 0;
}
