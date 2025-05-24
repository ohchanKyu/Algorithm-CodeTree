#include <iostream>
#include <queue>


using namespace std;

typedef pair<int,int> coord;
int N, M;
int grid[50][50];
int tempGrid[50][50];
bool visited[50][50];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(coord start);
void copy(int k);

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    int maxK = 0;
    int maxV = 0;
    for(int k=1;k<=100;k++){    
        copy(k);
        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if (tempGrid[i][j] != -1 && tempGrid[i][j] != -2){
                    cnt += 1;
                    bfs(coord(i,j));
                }
            }
        }
        if (cnt > maxV){
            maxV = cnt;
            maxK = k;
        }
    }
    cout << maxK << " " << maxV;
    return 0;
}

void copy(int k){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (grid[i][j] <= k) tempGrid[i][j] = -1;
            else tempGrid[i][j] = grid[i][j];
            visited[i][j] = false;
        }
    }
}

void bfs(coord start){

    queue<coord> q;
    q.push(start);
    visited[start.first][start.second] = true;
    tempGrid[start.first][start.second] = -2;
    while(!q.empty()){
        coord now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny] || tempGrid[nx][ny] == -1) continue;
            visited[nx][ny] = true;
            tempGrid[nx][ny] = -2;
            q.push(coord(nx,ny));
        }
    }
}
