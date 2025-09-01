#include <bits/stdc++.h>

using namespace std;

int n, m, r, c;
int grid[104][104];
queue<pair<int,int>> q;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int x,y;

int main() {
    cin >> n >> m >> r >> c;

    q.push({ --r,--c});
    grid[r][c] = 1;

    int t = 1;
    while(m--){
        int qSize = (int) q.size();
        queue<pair<int,int>> tempQ;        
        for(int i=0;i<qSize;i++){
            tie(x,y) = q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nx = x + dx[d] * t;
                int ny = y + dy[d] * t;
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (grid[nx][ny]) continue;
                grid[nx][ny] = 1;
                tempQ.push({ nx,ny });
            }
            tempQ.push({x,y});
        }
        q = tempQ;
        t++;
    }
    cout << q.size();
    return 0;
}
