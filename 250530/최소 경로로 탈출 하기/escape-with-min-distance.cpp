#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> coord;
int n, m;
int a[100][100];
int visited[100][100];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
void bfs(coord start);

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            visited[i][j] = -1;
        }
    }
    bfs(coord(0,0));
    cout << visited[n-1][m-1];
}

void bfs(coord start){

    queue<coord> q;
    q.push(start);
    visited[start.first][start.second] = 0;

    while(!q.empty()){
        
        coord now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (a[nx][ny] == 0) continue;
            if (visited[nx][ny] > -1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push(coord(nx,ny));
        }
    }
}
