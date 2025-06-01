#include <iostream>

using namespace std;

int n;
int dp[20];

int main() {

    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=n;i++){
        int cnt = 0;
        // root 1 ~ i
        for(int j=1;j<=i;j++){
            cnt += dp[j-1] * dp[i-j];
        }
        dp[i] = cnt;
    }
    cout << dp[n];
    return 0;
}
