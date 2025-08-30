#include <bits/stdc++.h>
#define prev nahc
using namespace std;
const int INF = 987654321;

int n;
int grid[100][100];
int dp[100][100][101];

int main() {

    cin >> n;

    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=1;k<=100;k++){
                dp[i][j][k] = INF;
            }
        }
    }
    // x,y까지 c라는 최솟값으로 진행할 때의 최대값의 최소값
    dp[0][0][grid[0][0]] = grid[0][0];

    for(int i=1;i<n;i++){
        // 현재의 grid 값
        int currnetValue = grid[0][i];
        for(int k=1;k<=100;k++){
            dp[0][i][min(k,currnetValue)] = min(dp[0][i][min(k,currnetValue)], max(currnetValue, dp[0][i-1][k]));
        }
    }
    for(int i=1;i<n;i++){
        int currnetValue = grid[i][0];
        for(int k=1;k<=100;k++){
            dp[i][0][min(k,currnetValue)] = min(dp[i][0][min(k,currnetValue)],max(currnetValue,dp[i-1][0][k]));
            
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            int currnetValue = grid[i][j];
            for(int k=1;k<=100;k++){
                dp[i][j][min(k,currnetValue)] = min(dp[i][j][min(k,currnetValue)], 
                max(currnetValue,min(dp[i][j-1][k],dp[i-1][j][k])));
            }
        }
    }
    int ans = INF;
    for(int k=1;k<=100;k++){
        if (dp[n-1][n-1][k] != INF){
            ans = min(ans,abs(dp[n-1][n-1][k] - k));
        }
    }
    cout << ans;
    return 0;
}
