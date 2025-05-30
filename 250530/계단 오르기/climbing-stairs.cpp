#include <iostream>
using namespace std;

int n;
// dp[N][0] -> N으로 갈 때 2계단으로 가기
// dp[N][1] -> N으로 갈 때 3계단으로 가기
long long dp[1001][2];
int mod = 10007;

int main() {
    cin >> n;
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[2][0] = 1;
    dp[2][1] = 0;
    dp[3][0] = 0;
    dp[3][1] = 1;
    
    for (int i = 4; i <= n; i++) {
       dp[i][0] = (dp[i-2][0] + dp[i-2][1]) % mod;
       dp[i][1] = (dp[i-3][0] + dp[i-3][1]) % mod;
    }
    cout << (dp[n][0] + dp[n][1]) % mod;

    return 0;
}