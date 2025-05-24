#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> coord;

int n, k;
int grid[100][100];
bool visited[100][100];
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
vector<coord> v;
void bfs(coord start);

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++){
        int r,c;
        cin >> r >> c;
        v.push_back(coord(r-1,c-1));
    }

    for(coord idx : v){
        bfs(idx);
    }
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (visited[i][j]) ans += 1;
        }
    }
    cout << ans;
    return 0;
}

void bfs(coord start){

    queue<coord> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        coord now = q.front();
        q.pop();

        int x = now.first;
        int y = now.second;
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || grid[nx][ny] == 1) continue;
            visited[nx][ny] = true;
            q.push(coord(nx,ny));
        }
    }
}