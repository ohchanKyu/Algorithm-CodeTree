#include <bits/stdc++.h>

using namespace std;
const int INF = -1e9;

int N, M;
int coin[100];
int dp[10004];

int main() {

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    fill(dp,dp+10004,INF);
    dp[0] = 0;

    for(int i=0;i<N;i++){
        int val = coin[i];
        for(int j=val;j<=M;j++){
           dp[j] = max(dp[j], dp[j-val] + 1);
        }
    }
    if (dp[M] == INF) cout << -1;
    else cout << dp[M];

    return 0;
}
