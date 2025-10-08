#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1004];
int A[1004];

int go(int idx){

    int &ret = dp[idx];
    if (ret != -1) return ret;

    ret = 0;
    for(int _size=1; _size<=A[idx];_size++){
        if (idx + _size >= N) continue;
        ret = max(ret, go(idx + _size) + 1);
    }
    return ret;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << go(0);

    return 0;
}