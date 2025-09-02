#include <bits/stdc++.h>

using namespace std;

int grid[4][4];
char dir;
int visited[4][4];

// 상 하 좌 우
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
map<char,int> mp;
void setting(){
    mp['U'] = 0;
    mp['D'] = 1;
    mp['L'] = 2;
    mp['R'] = 3;
}

void move(int x,int y,int dir){

    int sx = x;
    int sy = y;
    int target = grid[x][y];
    bool isMove = false;

    while(true){
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];
        // 범위 넘어감
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break;

        // 숫자가 있지만 같지 않음
        if (grid[nx][ny] && grid[nx][ny] != target) break;
        // 숫자가 있고 같음
        if (grid[nx][ny] && grid[nx][ny] == target){
            // 둘 다 충돌 일어나지 않음
            if (!visited[x][y] && !visited[nx][ny]){
                grid[x][y] = 0;
                grid[nx][ny] *= 2;
                visited[nx][ny] = 1;
                visited[x][y] = 1;
                return;
            }else break;
        }
        if (!grid[nx][ny]){
            isMove = true;
            sx = nx;
            sy = ny;
        }
    }
    if (isMove){
        grid[sx][sy] = grid[x][y];
        grid[x][y] = 0;
    }
}
void go(int dir){

    if (dir == 0){
        for(int j=0;j<4;j++){
            for(int i=1;i<4;i++){
                if (grid[i][j]) move(i,j,dir);
            }
        }
    }else if (dir == 1){
        for(int j=0;j<4;j++){
            for(int i=2;i>=0;i--){
                if (grid[i][j]) move(i,j,dir);
            }
        }
    }else if (dir == 2){
        for(int i=0;i<4;i++){
            for(int j=1;j<4;j++){
                if (grid[i][j]) move(i,j,dir);
            }
        }
    }else{
        for(int i=0;i<4;i++){
            for(int j=2;j>=0;j--){
                if (grid[i][j]) move(i,j,dir);
            }
        }
    }
}

int main() {

    setting();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;
    // U j=0~N i=1~N-1
    // D j=0~N i=N-2 ~ 0
    // R i=0~N j=1~N-1
    // L i=0~N j=N-2 ~ 0
    go(mp[dir]);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
