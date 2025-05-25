#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> coord;
int n, k, m;
int grid[100][100];
bool visited[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<coord> rock;
vector<coord> visitList;
int rockSize;
void dfs(int depth,vector<coord> rockList, int start);
void bfs(coord start);
int ans = 0;
void clear();

int main() {

    cin >> n >> k >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 1) rock.push_back(coord(i,j));
        }
    }
    rockSize = rock.size();
    for (int i = 0; i < k; i++) {
        int r,c;
       cin >> r >> c;
       visitList.push_back(coord(r-1,c-1));
    }
    vector<coord> startV;
    dfs(0,startV,0);
    cout << ans;
    return 0;
}
void clear(){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visited[i][j]) cnt += 1;
            visited[i][j] = false;
        }
    }
    ans = max(ans,cnt);
}
void dfs(int depth,vector<coord> rockList, int start){
    
    if (depth == m){
        for(coord r : rockList){
            grid[r.first][r.second] = 0;
        }
        for(coord r : visitList){
            bfs(r);
        }
        for(coord r : rockList){
            grid[r.first][r.second] = 1;
        }
        clear();
        return;
    }
    for(int i=start;i<rockSize;i++){
        rockList.push_back(rock[i]);
        dfs(depth+1,rockList,i+1);
        rockList.pop_back();
    }
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
