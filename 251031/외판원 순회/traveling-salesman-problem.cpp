#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n;
int A[10][10];
int dp[14][(1 << 11)];

int go(int idx,int nums){

    if (nums == (1 << n) - 1){
        if (A[idx][0] == 0) return INF;
        else return A[idx][0];
    }

    int &ret = dp[idx][nums];
    if (ret != -1) return ret;

    ret = INF;    
    for(int i=0;i<n;i++){
        if (nums & (1 << i) || A[idx][i] == 0) continue;
        int cost = A[idx][i];
        ret = min(ret, go(i, nums | (1 << i)) + cost);
    }
    return ret;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << go(0,1);

    return 0;
}
