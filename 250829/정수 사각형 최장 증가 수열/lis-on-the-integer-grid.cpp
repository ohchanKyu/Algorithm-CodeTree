#include <bits/stdc++.h>
#define prev nahc

using namespace std;

int n;
int grid[500][500];
int dp[500][500];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int go(int x, int y){

    int &ret = dp[x][y];
    if (ret != -1) return ret;

    ret = 1;
    for(int d=0;d<4;d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (grid[nx][ny] <= grid[x][y]) continue;
        ret = max(ret,go(nx,ny) + 1);
    }
    return ret;
}

int main() {

    cin >> n;

    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int maxV = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maxV = max(maxV,go(i,j));
        }
    }
    cout << maxV;

    return 0;
}
