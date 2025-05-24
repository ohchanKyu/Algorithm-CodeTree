#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> coord;
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
int n;
int grid[25][25];
bool visited[25][25];
vector<int> personCnt;
void bfs(coord start);

int main() {
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1){
                bfs(coord(i,j));
                cnt += 1;
            }
        }
    }
    cout << cnt << "\n";
    sort(personCnt.begin(),personCnt.end());
    for(int n : personCnt){
        cout << n << "\n";
    }
    return 0;
}
void bfs(coord start){

    queue<coord> q;
    q.push(start);
    grid[start.first][start.second] = 2;
    visited[start.first][start.second] = true;
    int person = 1;

    while(!q.empty()){
        coord now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || grid[nx][ny] == 0)  continue;
            visited[nx][ny] = true;
            grid[nx][ny] = 2;
            person += 1;
            q.push(coord(nx,ny));        
        }
    }
    personCnt.push_back(person);
}
