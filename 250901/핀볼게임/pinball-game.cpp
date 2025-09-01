#include <bits/stdc++.h>

using namespace std;

int n;
int grid[100][100]; 
int visited[100][100][4];

int pinbol[2][4] = {
    {3,2,1,0},
    {2,3,0,1}
};
int ret;
// 상 하 좌 우
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

int go(int sx, int sy, int dir){

    memset(visited, 0, sizeof(visited));
    int x = sx, y = sy, d = dir;
    int t = 0;

    while (true) {
        if (visited[x][y][d]) return 0;
        visited[x][y][d] = 1;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) return t + 2;
        int v = grid[nx][ny];
        if (v == 1) d = pinbol[0][d];
        else if (v == 2) d = pinbol[1][d];

        x = nx; y = ny;
        t++;
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for(int i=0;i<n;i++){
        ret = max(ret,go(0,i,1));
        ret = max(ret,go(i,0,3));
        ret = max(ret,go(i,n-1,2));
        ret = max(ret,go(n-1,i,0));
    }
    cout << ret;

    return 0;
}
