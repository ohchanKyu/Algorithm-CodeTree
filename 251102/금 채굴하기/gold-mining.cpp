#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[20][20];
int visited[20][20];
int ret;
int maxCost, maxK;

int calCost(int k){
    return k * k + (k + 1) * (k + 1);
}
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

void check(int x,int y,int k){
    
    memset(visited,0,sizeof(visited));
    
    int cnt = 0;
    queue<pair<int,int>> q;
    visited[x][y] = 1;
    q.push({x,y});
    if (grid[x][y]) cnt++;
    
    while(q.size()){
        tie(x,y) = q.front();
        q.pop();
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || visited[x][y] - 1 >= k) continue;
            visited[nx][ny] = visited[x][y] + 1;
            if (grid[nx][ny]) cnt++;
            q.push({nx,ny});
        }
    }
    ret = max(ret,cnt);
}

int main() {
    cin >> n >> m;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]) cnt++;
        }
    }
    maxCost = cnt * m;
    while(true){
        int tmp = calCost(maxK);
        if (maxCost >= tmp) maxK++;
        else break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            check(i,j, maxK - 1);
        }
    }
    cout << ret;

    return 0;
}
