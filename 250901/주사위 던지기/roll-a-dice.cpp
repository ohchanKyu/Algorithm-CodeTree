#include <bits/stdc++.h>

using namespace std;

int n, m;
int r, c;
char dir;
// 상 하 좌 우
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
int directions[10004];
int grid[104][104];
int ret;
int dice[7];

void setting(){
    for(int i=1;i<=6;i++){
        dice[i] = i;
    }
}
void cal(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ret += grid[i][j];
        }
    }
}
void movement(int dir){
    // 하
    int tmp;
    if (dir == 1){
        tmp = dice[6];
        dice[6] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = tmp;
    // 좌
    }else if (dir == 2){
        tmp = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = tmp;
    // 우
    }else if (dir == 3){
        tmp = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = tmp;
    // 상
    }else{
        tmp = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = tmp;
    }
}
void go(int x,int y,int index){

    if (index == m){
        cal();
        return;
    }
    
    int d = directions[index];
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (nx < 0 || ny < 0 || nx >= n || ny >= n){
        go(x,y,index+1);
    }else{
        movement(d);
        grid[nx][ny] = dice[6];
        go(nx,ny,index+1);
    }

}
int main() {
    cin >> n >> m >> r >> c;
    r--;
    c--;
    setting();
    for (int i = 0; i < m; i++) {
        cin >> dir;
        if (dir == 'L'){
            directions[i] = 2;
        }
        else if (dir == 'D') directions[i] = 1;
        else if (dir == 'R') directions[i] = 3;
        else directions[i] = 0;
    }
    grid[r][c] = 6;
    go(r,c,0);
    cout << ret;
    return 0;
}
