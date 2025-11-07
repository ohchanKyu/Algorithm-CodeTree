#include <bits/stdc++.h>

using namespace std;

int N, M;
int coin[100];
int dp[10004];

int main() {

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int i=0;i<N;i++){
        int val = coin[i];
        for(int j=val;j<=M;j++){
            dp[j] = max(dp[j], dp[j-val] + 1);
        }
    }

    cout << dp[M];
    return 0;
}
