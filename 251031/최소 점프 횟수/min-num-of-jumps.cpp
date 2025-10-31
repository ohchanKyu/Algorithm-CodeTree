#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

int n;
int num[10];
int dp[14];

int go(int idx){
    
    if (idx >= n) return INF;
    if (idx == n-1) return 0;

    int &ret = dp[idx];
    if (ret != -1) return ret;

    int cur = num[idx];

    ret = INF;
    for(int i=1;i<=cur;i++){
        ret = min(ret, go(idx+i) + 1);
    }
    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    memset(dp,-1,sizeof(dp));
    int ret = go(0);
    if (ret == INF) cout << -1;
    else cout << ret;
    return 0;
}
