#include <iostream>

using namespace std;

int n;
int mod = 10007;
// dp[N][0] - N번째까지를 채웠을 때 1x2 하나로 채움
// dp[N][1] - N번째까지를 채웠을 때 2x1 2개로 채움
int dp[1001][2];

int main() {
    
    cin >> n;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;

    for(int i=3;i<=n;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-2][0] + dp[i-2][1]) % mod;
    }
    cout << (dp[n][0] + dp[n][1]) % mod;
    return 0;
}
