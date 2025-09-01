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

int go(int x,int y,int dir){

    int t = 0;
    memset(visited,0,sizeof(visited));

    if (grid[x][y] == 1) dir = pinbol[0][dir];
    else if (grid[x][y] == 2) dir = pinbol[1][dir];
    visited[x][y][dir] = 1;
    
    while(true){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) return t + 2;
        if (grid[nx][ny] == 1){
            dir = pinbol[0][dir];
        }else if (grid[nx][ny] == 2){
            dir = pinbol[1][dir];
        }
        if (visited[nx][ny][dir]) return 0;
        visited[nx][ny][dir] = 1;
        x = nx;
        y = ny;
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
