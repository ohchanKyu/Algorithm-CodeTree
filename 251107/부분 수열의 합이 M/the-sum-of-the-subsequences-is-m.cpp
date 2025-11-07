#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

int n, m;
int A[100];
int dp[10004];

int main() {

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    fill(dp,dp+10004,INF);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        int val = A[i];
        for(int j=m;j>=val;j--){
            dp[j] = min(dp[j], dp[j-val] + 1);
        }
    }
    if (dp[m] == INF) cout << -1;
    else cout << dp[m];
    return 0;
}
