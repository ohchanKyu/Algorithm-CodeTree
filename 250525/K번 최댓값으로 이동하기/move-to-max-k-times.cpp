#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> coord;
int n, k;
int grid[100][100];
int r, c;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool visited[100][100];
void bfs(coord start,int value);
void clear();

coord ans;

struct Compare {
    bool operator()(const coord& a,const coord& b){
        if (a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main() {

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    ans = coord(r-1,c-1);
    for(int i=0;i<k;i++){
        clear();
        bfs(ans,grid[ans.first][ans.second]);
    }
    cout << ans.first + 1 <<  " " << ans.second + 1;
    return 0;
}
void clear(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
}
void bfs(coord start,int value){

    queue<coord> q;
    q.push(start);
    visited[start.first][start.second] = true;

    int maxV = 0;
    while(!q.empty()){
        coord now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || grid[nx][ny] >= value) continue;
            visited[nx][ny] = true;
            maxV = max(maxV, grid[nx][ny]);
            q.push(coord(nx,ny));
        }
    }
    priority_queue<coord,vector<coord>,Compare> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (grid[i][j] == maxV && visited[i][j]){
                pq.push(coord(i,j));
            }
        }
    }
    ans = pq.top();
}