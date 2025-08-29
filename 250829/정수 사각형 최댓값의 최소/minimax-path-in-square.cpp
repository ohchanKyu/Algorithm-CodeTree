#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dp[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    dp[0][0] = grid[0][0];
    for(int j=1;j<n;j++){
        dp[0][j] = max(dp[0][j-1],grid[0][j]);
        dp[j][0] = max(dp[j-1][0],grid[j][0]);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if (i == n-1 && j == n-1) dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}
