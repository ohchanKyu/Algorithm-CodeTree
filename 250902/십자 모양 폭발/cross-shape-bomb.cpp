#include <bits/stdc++.h>

using namespace std;

int n;
int grid[200][200];
int r, c;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

void downNumber(){
    
    for(int j=0;j<n;j++){
        for(int i=n-2;i>=0;i--){
            if (grid[i][j] == 0) continue;
            int cx = i;
            int cy = j;
            int tx = 0;
            int ty = 0;

            bool isMove = false;
            while(true){
                int nx = cx + 1;
                int ny = cy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                if (!grid[nx][ny]){
                    tx = nx;
                    ty = ny;
                    isMove = true;
                }else break;
                cx = nx;
                cy = ny;
            }
            if (isMove){
                grid[tx][ty] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    }
}
void bomb(int r,int c){

    int sx = r;
    int sy = c;
    int ends = grid[r][c];
    grid[r][c] = 0;
    for(int d=0;d<4;d++){

        int x = sx;
        int y = sy;
        for(int cnt = 0; cnt < ends -1 ;cnt++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
            grid[nx][ny] = 0;
            x = nx;
            y = ny;
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

    cin >> r >> c;
    r--; c--;
    bomb(r,c);
    downNumber();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
