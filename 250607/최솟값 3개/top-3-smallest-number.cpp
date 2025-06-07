#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100000];

int main() {

    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
        if (i < 3){
            cout << -1 << "\n";
            continue;
        }
        long long ans = 1;
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int third = pq.top(); pq.pop();
        cout << (long long)first * second * third << "\n";
        pq.push(first); pq.push(second); pq.push(third);
    }
    


    return 0;
}
