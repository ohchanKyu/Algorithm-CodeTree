#include <bits/stdc++.h>

using namespace std;

int n, t;
int u[200];
int d[200];
vector<int> v;

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int tmp = t % (2 * n);
    rotate(v.rbegin(),v.rbegin() + tmp ,v.rend());
    for(int i=0;i<2*n;i++){
        cout << v[i] << " ";
        if (i == n - 1) cout << "\n";
    }
    return 0;
}
