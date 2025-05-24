#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> coord;
int n;
int grid[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool visited[100][100];
int maxV = 0;
int cnt = 0;
int current = 0;
void bfs(coord start);

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0){
                current = grid[i][j];                
                bfs(coord(i,j));
            }
        }
    }
    cout << cnt << " " << maxV;

    return 0;
}
void bfs(coord start){

    queue<coord> q;
    int count = 1;
    q.push(start);
    visited[start.first][start.second] = true;
    grid[start.first][start.second] = 0;

    while(!q.empty()){
        coord now = q.front();
        q.pop();

        int x = now.first;
        int y=  now.second;
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (current != grid[nx][ny]) continue;
            visited[nx][ny] = true;
            grid[nx][ny] = 0;
            count += 1;
            q.push(coord(nx,ny));
        }
    }
    if (count >= 4){
        cnt += 1;
    }
    maxV = max(maxV,count);
}


