#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> coord;
int n, m;
int grid[100][100];
int dx[] = {1,0};
int dy[] = {0,1};
bool visited[100][100];
bool isSuccess = false;
void bfs();

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    bfs();
    cout << isSuccess;
    return 0;
}
void bfs(){
    queue<coord> q;
    q.push(coord(0,0));
    visited[0][0] = true;

    while(!q.empty()){
        coord now = q.front();
        q.pop();

        int x = now.first;
        int y = now.second;
        if (x == n-1 && y == m-1){
            isSuccess = true;
            return;
        }
        for(int d=0;d<2;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == 1){
                visited[nx][ny] = true;
                q.push(coord(nx,ny));
            }
        }
    }
}