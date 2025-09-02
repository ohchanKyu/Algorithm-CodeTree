#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[200][200];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

void move(){
    
    for(int j=0;j<n;j++){
        for(int i=n-2;i>=0;i--){
            int x = i;
            int y = j;
            int tx,ty;
            bool isMove = false;
            while(true){
                int nx = x + 1;
                int ny = y;
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                if (grid[nx][ny]) break;
                tx = nx;
                ty = ny;
                isMove = true;
                x = nx;
                y = ny;
            }
            if (isMove){
                grid[tx][ty] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    }
}
void bomb(int col){
    
    int row = -1;
    for(int i=0;i<n;i++){
        if (grid[i][col]){
            row = i;
            break;
        }
    }
    if (row == -1) return;
    int _size = grid[row][col];
    for(int d=0;d<4;d++){
        for(int i=0;i<_size;i++){
           int nx = row + dx[d] * i; 
           int ny = col + dy[d] * i;
           if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
           grid[nx][ny] = 0;
        }
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        bomb(--c);
        move();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}
