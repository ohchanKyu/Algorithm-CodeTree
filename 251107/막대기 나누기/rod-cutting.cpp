#include <bits/stdc++.h>

using namespace std;

int n;
int profit[104];
int dp[104];

int go(int len){

    if (len == 0) return 0;

    int &ret = dp[len];
    if (ret != -1) return ret;

    ret = 0;
    for(int i=1;i<=n;i++){
        if (len < i) continue;
        ret = max(ret,go(len - i) + profit[i]);
    }

    return ret;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << go(n);

    return 0;
}
