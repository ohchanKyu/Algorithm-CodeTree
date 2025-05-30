#include <iostream>

using namespace std;

int N;
long dp[46];

int main() {

    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3;i<=45;i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[N];
    return 0;
}
