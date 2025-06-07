#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100000];

int main() {
    
    cin >> n;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        q.push(arr[i]);
    }

    while(true){
        if (q.size() == 1){
            cout << q.top();
            return 0;
        }else if (q.size() == 0){
            cout << -1;
            return 0;
        }
        int first = q.top(); q.pop();
        int second = q.top(); q.pop();
        if (first == second) continue;
        else{
            q.push(first - second);
        }
    }
    return 0;
}
