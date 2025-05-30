#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> coord;
int n;
int r1, c1, r2, c2;
int visited[101][101];
int dx[] = {1,-1,1,-1,2,-2,2,-2};
int dy[] = {2,-2,-2,2,1,1,-1,-1};

int main() {
    
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = -1;
        }
    }
    // Please write your code here.
    queue<coord> q;
    q.push(coord(r1-1,c1-1));
    visited[r1-1][c1-1] = 0;

    while(!q.empty()){
        coord now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        for(int d=0;d<8;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] > -1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push(coord(nx,ny));
        }
    }
    cout << visited[r2-1][c2-1];
    return 0;
}
