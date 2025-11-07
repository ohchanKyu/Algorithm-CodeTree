#include <iostream>

using namespace std;

int N, M;
int w[100], v[100];
int dp[10004];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i=0;i<N;i++){
        int weight = w[i];
        int val = v[i];
        for(int j=M;j>=weight;j--){
            dp[j] = max(dp[j], dp[j-weight] + val);
        }
    }
    cout << dp[M];
    
    return 0;
}
