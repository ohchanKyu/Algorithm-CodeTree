#include <bits/stdc++.h>

using namespace std;

int N;
int x, y;
char grid[101][101];
int visited[101][101][4];

// 오른 위 왼 아래 반시계 +1
// 시계는  + 3
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
// 오른 위 왼쪽 아래
const int walld[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool isRightWall(int x,int y, int dir){

    int nx = x + walld[dir][0];
    int ny = y + walld[dir][1];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
    if (grid[nx][ny] == '#') return true;
    return false;
}
void go(int x, int y, int cnt, int dir){
    
    visited[x][y][dir] = 1;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    // 탈출
    bool isCurrentRightWall = isRightWall(x,y,dir);
    if (nx < 0 || ny < 0 || nx >= N || ny >= N && isRightWall){
        cout << cnt + 1;
        exit(0);
    }
    // 벽이 있는 경우
    bool isNextRightWall = isRightWall(nx,ny,dir);
    if (grid[nx][ny] == '#' && isCurrentRightWall){
        int nextDir = (dir + 1) % 4;
        if (!visited[x][y][nextDir]){
            go(x,y,cnt ,nextDir);
        }
    }
    else if (isCurrentRightWall && isNextRightWall){
        if (!visited[nx][ny][dir]) go(nx,ny,cnt+1,dir);
    }else if (isCurrentRightWall && !isNextRightWall){
        dir = (dir + 3) % 4;
        nx = nx + dx[dir];
        ny = ny + dy[dir];
        if (!visited[nx][ny][dir]){
            go(nx,ny,cnt+2,dir);
        }
    }
    cout << -1;
    exit(0);
}

int main() {
    cin >> N;
    cin >> x >> y;
    x--; y--;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    go(x,y,0,0);
    return 0;
}
