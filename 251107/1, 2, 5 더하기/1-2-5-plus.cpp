#include <bits/stdc++.h>

using namespace std;
const int mod = 10007;

int N;
int A[3] = {1,2,5};
int dp[1004];

int main() {
    
    cin >> N;
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=N;i++){
        if (i < 5){
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }else{
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-5]) % mod;
        }
       
    }
    cout << dp[N] % mod;
    return 0;
}