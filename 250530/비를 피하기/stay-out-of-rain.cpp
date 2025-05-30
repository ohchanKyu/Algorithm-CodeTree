#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> coord;
int n, h, m;
int grid[100][100];
int visited[100][100];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int result[100][100];
void bfs(coord start);
vector<coord> persons;

int main() {

    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) persons.push_back(coord(i,j));
        }
    }
    for(coord person : persons){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = -1;
            }
        }
        bfs(person);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
void bfs(coord start){

    queue<coord> q;
    q.push(start);
    visited[start.first][start.second] = 0;
    int ans = -1;

    while(!q.empty()){
        
        coord now = q.front();
        q.pop();

        int x = now.first;
        int y = now.second;
        if (grid[x][y] == 3){
            ans = visited[x][y];
            break;
        }
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] > -1 || grid[nx][ny] == 1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push(coord(nx,ny));
        }
    }
    result[start.first][start.second] = ans;
}
