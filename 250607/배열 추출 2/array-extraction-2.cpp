#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 100000;
int n;
int x[MAX_N];

struct Compare{

    bool operator()(const int &a,const int &b) const {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};
int main() {

    cin >> n;
    priority_queue<int,vector<int>,Compare> q;
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

    // Please write your code here.

    return 0;
}
