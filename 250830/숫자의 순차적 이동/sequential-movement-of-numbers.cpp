#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[20][20];
const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};

pair<int,int> findLocation(int x){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (grid[i][j] == x){
                return {i,j};
            }
        }
    }
}
void swapX(int x, int y){

    int t = 0;
    pair<int,int> tlo;
    for(int d=0;d<8;d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (t < grid[nx][ny]){
            t = grid[nx][ny];
            tlo = { nx,ny };
        }
    }
    if (t != 0){
        int temp = grid[x][y];
        int tx = tlo.first;
        int ty = tlo.second;
        grid[x][y] = grid[tx][ty];
        grid[tx][ty] = temp;
    }
}
int main() {
    cin >> n >> m;

    int maxV = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            maxV = max(maxV,grid[i][j]);
        }
    }

    while(m--){
            for(int i=1;i<=maxV;i++){
                pair<int,int> lo = findLocation(i);
                swapX(lo.first,lo.second);
            }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
