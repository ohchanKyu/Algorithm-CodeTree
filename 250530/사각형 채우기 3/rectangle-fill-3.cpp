#include <iostream>

using namespace std;

int n;
int mod = 1000000007;
// dp[n][0] -> n번째를 채울 때 1x2를 사용
// dp[n][1] -> n번째를 채울 때 2x1를 사용
// dp[n][2] -> n번째를 채울 때 1x1 2개를 사용
int dp[1001][3];
int main() {
    
    cin >> n;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[1][2] = 1;
    dp[2][0] = 2;
    dp[2][1] = 3;
    dp[2][2] = 2;

    for(int i=3;i<=n;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % mod; // 7
        dp[i][1] = ((dp[i-2][0] + dp[i-2][1] + dp[i-2][2]) * 3 + dp[i-1][1]-1) % mod; // 8
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % mod; // 7
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
    return 0;
}
