#include <bits/stdc++.h>

using namespace std;

int n;
int grid[50][50];
int temp[50][50];
int ret;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int cal(){
    int ans = 0;
    for(int j=0;j<n;j++){
        for(int i=0;i<n-1;i++){
            if (temp[i][j] && temp[i][j] == temp[i+1][j]) ans++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if (temp[i][j] && temp[i][j] == temp[i][j+1]) ans++;
        }
    }
    return ans;
}

void bomb(int x,int y){

    memcpy(temp,grid,sizeof(temp));
    int target = temp[x][y];
    temp[x][y] = 0;
    for(int i=1;i<=target-1;i++){
        for(int d=0;d<4;d++){
           int nx = x + dx[d] * i;
           int ny = y + dy[d] * i;
           if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
           temp[nx][ny] = 0; 
        }
    }
}
void move(){

    for(int j=0;j<n;j++){
        for(int i=n-1;i>=0;i--){
            if (!temp[i][j]) continue;
            int sx = i;
            int sy = j;
            int tx,ty;
            bool isMove = false;
            while(true){
                int nx = sx + 1;
                int ny = sy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                if (temp[nx][ny]) break;
                tx = nx;
                ty = ny;
                isMove = true;
                sx = nx;
                sy = ny;
            }
            if (isMove) {
                temp[tx][ty] = temp[i][j];
                temp[i][j] = 0;
            }
        }
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bomb(i,j);
            move();
            ret = max(ret,cal());
        }
    }    
    cout << ret;
    return 0;
}
