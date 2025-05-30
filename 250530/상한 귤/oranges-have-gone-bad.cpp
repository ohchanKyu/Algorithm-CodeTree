#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> coord;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, k;
int grid[100][100];
int visited[100][100];
queue<coord> hurts;

int main() {

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2){
                hurts.push(coord(i,j));
                visited[i][j] = 0;
            }else{
                visited[i][j] = -1;
            }
        }
    }
    
    while(!hurts.empty()){

        int qSize = hurts.size();
        
        for(int i=0;i<qSize;i++){
            coord now = hurts.front();
            hurts.pop();
            int x = now.first;
            int y = now.second;
            for(int d=0;d<4;d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (visited[nx][ny] > -1 || grid[nx][ny] == 0) continue;
                visited[nx][ny] = visited[x][y] + 1;
                hurts.push(coord(nx,ny));
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (visited[i][j] == -1 && grid[i][j] == 1){
                cout << -2 << " ";
            }else{
                cout << visited[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
