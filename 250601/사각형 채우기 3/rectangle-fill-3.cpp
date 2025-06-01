#include <iostream>
using namespace std;

int n;
int mod = 1000000007;
int dp[1001];

int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;
    
    long long sum = 0;

    for(int i = 2; i <= n; i++) {
        if (i >= 3) sum = (sum + dp[i-3]) % mod;
        dp[i] = (dp[i-1] * 2LL + dp[i-2] * 3LL + sum * 2LL) % mod;
    }

    cout << dp[n] << '\n';
    return 0;
}