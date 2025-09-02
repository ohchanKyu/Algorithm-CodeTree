#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int grid[100][100];
int temp[100][100];

void rotationArr(){

    memcpy(temp,grid,sizeof(temp));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grid[i][j] = temp[N-j-1][i];
        }
    }
}
void move(){
    for(int j=0;j<N;j++){
        for(int i=N-1;i>=0;i--){
            if (!grid[i][j]) continue;
            int x = i;
            int y = j;
            int tx,ty;
            bool isMove = false;
            while(true){
                int nx = x + 1;
                int ny = y;
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
                if (grid[nx][ny]) break;
                tx = nx;
                ty = ny;
                isMove = true;
                x = nx;
                y = ny;
            }
            if(isMove){
                grid[tx][ty] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    }
}
void bomb(){
    
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            if (!grid[i][j]) continue;
            int cnt = 1;
            vector<pair<int,int>> tmp;
            int x = i;
            int y = j;
            tmp.push_back({ x,y });
            while(true){
                int nx = x + 1;
                int ny = y;
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
                if (grid[nx][ny] != grid[i][j]) break;
                cnt++;
                tmp.push_back({nx,ny});
                x = nx;
                y = ny;
            }
            if (cnt >= M){
                for(auto it : tmp){
                    grid[it.first][it.second] = 0;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    while(K--){
        bomb();
        move();
        rotationArr();
        move();
    }
    bomb();
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if (grid[i][j]) ans++;
        }
    }
    cout << ans;
    return 0;
}
