#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

typedef pair<int,int> coord;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int n, k;
int grid[100][100];
int visited[100][100];
int r1, c1, r2, c2;
int ans = INT_MAX;
vector<coord> walls;
int bfs();
void dfs(int depth,int start,vector<coord> targets);
void clear();

int main() {

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) walls.push_back(coord(i,j));
        }
    }
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    vector<coord> target;
    dfs(0,0,target);
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}

void clear(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = -1;
        }
    }
}

void dfs(int depth,int start,vector<coord> targets){

    if (depth == k){
        clear();
        for(coord idx : targets){
            grid[idx.first][idx.second] = 0;
        }
        int result = bfs();
        for(coord idx : targets){
            grid[idx.first][idx.second] = 1;
        }
        ans = min(ans,result);
        return;
    }

    for(int i=start;i<walls.size();i++){
        targets.push_back(walls[i]);
        dfs(depth+1,i+1,targets);
        targets.pop_back();
    }
}

int bfs(){

    queue<coord> q;
    q.push(coord(r1,c1));
    visited[r1][c1] = 0;
    
    while(!q.empty()){
        coord now = q.front();
        q.pop();

        int x = now.first;
        int y = now.second;
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (grid[nx][ny] == 1 || visited[nx][ny] > -1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push(coord(nx,ny));
        }
    }
    if (visited[r2][c2] == -1) return INT_MAX;
    else return visited[r2][c2];
}
