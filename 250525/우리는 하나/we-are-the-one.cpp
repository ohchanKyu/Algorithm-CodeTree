#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> coord;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n, k, U,D;
int grid[8][8];
bool visited[8][8];
vector<coord> v;
int ans;
void bfs(coord start);
void dfs(int depth, int start, vector<coord> coordList);

int main() {

    cin >> n >> k >> U >> D;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            v.push_back(coord(i,j));
        }
    }
    vector<coord> coordList;
    dfs(0,0,coordList);
    cout << ans;
    return 0;
}

void dfs(int depth, int start, vector<coord> coordList){

    if (depth == k){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        for(coord idx : coordList){
            bfs(idx);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (visited[i][j]) cnt += 1;
            }
        }
        ans = max(ans,cnt);
        return;
    }
    for(int i=start;i<v.size();i++){
        coordList.push_back(v[i]);
        dfs(depth+1,i+1,coordList);
        coordList.pop_back();   
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
            if (visited[nx][ny]) continue;
            int diff = abs(grid[x][y] - grid[nx][ny]);
            if (diff >= U && diff <= D) {
                visited[nx][ny] = true;
                q.push(coord(nx,ny));
            }
        }
    }
}