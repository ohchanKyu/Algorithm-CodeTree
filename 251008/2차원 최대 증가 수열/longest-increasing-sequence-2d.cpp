#include <bits/stdc++.h>

using namespace std;

int N,M;
int grid[54][54];
int dp[54][54];

int go(int x,int y){

    int &ret = dp[x][y];
    if (ret != -1) return ret;

    int cur = grid[x][y];
    ret = 1;
    for(int i=x+1;i<N;i++){
        for(int j=y+1;j<M;j++){
            if (cur >= grid[i][j]) continue;
            ret = max(ret,go(i,j) + 1);
        }
    }
    return ret;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> grid[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << go(0,0);

    return 0;
}