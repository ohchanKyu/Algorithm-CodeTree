#include <bits/stdc++.h>

using namespace std;

int n, t;
vector<int> v;

int main() {
    cin >> n >> t;

    for (int i = 0; i < 3 * n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int tmp = t % (3 * n);
    rotate(v.rbegin(),v.rbegin() + tmp, v.rend());
    for(int i=1;i<=3*n;i++){
        cout << v[i-1] << " ";
        if (i % n == 0){
            cout << "\n";
        }
    }

    return 0;
}
