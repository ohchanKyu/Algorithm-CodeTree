#include <bits/stdc++.h>

using namespace std;

int N, M;
int w[100], v[100];
int dp[104][10004];

int go(int idx,int weight){
    
    if (idx == N || weight > M) return 0;
    int &ret = dp[idx][weight];
    if (ret != -1) return ret;

    ret = 0;
    ret = max(ret, go(idx+1,weight));

    int cnt = 1;
    while(true){
        int tmp = cnt * w[idx];
        if (tmp + weight > M) break;
        ret = max(ret,go(idx+1, weight + tmp) + cnt * v[idx]);
        cnt++;
    }

    return ret;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << go(0,0);
    return 0;
}
