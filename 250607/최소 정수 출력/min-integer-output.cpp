#include <iostream>
#include <queue>

using namespace std;

int n;
int x[200000];

int main() {
    
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> q;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] != 0) q.push(x[i]);
        else{
            if (q.empty()) cout << 0 << "\n";
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
    }
    return 0;
}
