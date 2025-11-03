#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int grid[100][100];
int temp[100][100];
// 0 1 2 3
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
void rotateArr(int r1,int c1,int r2,int c2){

    int dir = 0;
    int sx = r1;
    int sy = c1;
    int rowL = c2 - c1;
    int colL = r2 - r1;
    int tmp = grid[sx][sy];
    while(true){
        if (dir == 4) break;
        int k = (dir & 1) ? colL : rowL;
        for(int i=1;i<=k;i++){
            int nx = sx + dx[dir];
            int ny = sy + dy[dir];
            int cur = grid[nx][ny];
            grid[nx][ny] = tmp;
            tmp = cur;
            sx = nx;    
            sy = ny;
        }
        dir += 1;
    }
}
bool is_range(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
void changeArr(int r1,int c1,int r2,int c2){
    
    memcpy(temp,grid,sizeof(temp));
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
            int sum = grid[i][j];
            int cnt = 1;
            for(int d=0;d<4;d++){
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (!is_range(nx,ny)) continue;
                sum += grid[nx][ny];
                cnt++;
            }
            temp[i][j] = sum / cnt;
        }
    }
    memcpy(grid,temp,sizeof(grid));
}
int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> grid[i][j];

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        rotateArr(r1,c1,r2,c2);
        changeArr(r1,c1,r2,c2);
    }
    print();

    return 0;
}
