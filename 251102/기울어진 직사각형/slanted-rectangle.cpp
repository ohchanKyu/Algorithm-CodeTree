#include <bits/stdc++.h>

using namespace std;

int n;
int grid[20][20];
int ret;

bool is_range(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}
// 1 2 3 4
const int dx[] = {-1,-1,1,1};
const int dy[] = {1,-1,-1,1};


int calMaxCoord(int x,int y, int dir){

    int val = 0;
    while(true){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!is_range(nx,ny)) break;
        x = nx;
        y = ny;
        val++;
    }    
    return val;
}

void cal(int x,int y, int row, int col){

    int tmp = 0;
    for(int d=0;d<4;d++){
        int t = (d & 1) ? col : row;
        for(int i=1;i<=t;i++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!is_range(nx,ny)) return;
            tmp += grid[nx][ny];
            x = nx;
            y = ny;
        }
    }
    ret = max(ret, tmp);

}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            int row = calMaxCoord(i,j,0);
            if (!row) continue;
            for(int r=1;r<=row;r++){
                int mx = i + dx[0] * r;
                int my = j + dy[0] * r;
                int col = calMaxCoord(mx,my,1);
                if (col == 0) continue;
                for(int c=1;c<=col;c++){
                    cal(i,j,r,c);
                }
            }
        }
    }
    cout << ret;

    return 0;
}
