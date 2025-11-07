#include <bits/stdc++.h>

using namespace std;

int n, m;
int A[100];
int dp[10004];

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    dp[0] = 1;
    for(int i=0;i<n;i++){
        int val = A[i];
        for(int j=m;j>=val;j--){
            dp[j] += dp[j-val];
        }
    }
    if (dp[m]) cout << "Yes";
    else cout << "No";

    return 0;
}
