#include <iostream>

using namespace std;

int n;

// dp[N][0] 은 N층까지 갈 때 2계단을 올라가는 경우
// dp[N][1] 은 N층까지 갈 때 3계단을 올라가는 경우

int dp[1001][2];

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
    
    for(int i=4;i<=1000;i++){
        dp[i][0] = dp[i-2][0] + 1;
        dp[i][1] = dp[i-3][1] + 1;
    }
    cout << dp[n][0] + dp[n][1];

    return 0;
}