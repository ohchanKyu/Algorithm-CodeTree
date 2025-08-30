#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
int x[2500];
int y[2500];
char d[2500];
int visited[54][54];

struct Element{
    int x,y,d;
};
vector<Element> v;

// 위쪽 오른쪽 아래 왼쪽
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

void move() {

    memset(visited,-1,sizeof(visited));
    for (auto &it : v) {
        int x = it.x;
        int y = it.y;
        int dir = it.d;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
            dir = (dir + 2) % 4; 
            nx = x;
            ny = y;
        }
        if (visited[nx][ny] == -1){
            visited[nx][ny] = dir;
        }else{
            visited[nx][ny] = -2;
        }
    }

    v.clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] != -1 && visited[i][j] != -2){
                v.push_back({i,j,visited[i][j]});
            }
        }
    }
}
int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        v.clear();
        for (int i = 0; i < M; i++) {
            cin >> x[i] >> y[i] >> d[i];
            int dir;
            if (d[i] == 'U') dir = 0;
            else if (d[i] == 'D') dir = 2;
            else if (d[i] == 'R') dir = 1;
            else dir = 3;
            v.push_back({ --x[i], --y[i], dir});
        }
        for(int tt=0; tt < 2 * N; tt++) move();
        cout << v.size() << "\n";
    }
    return 0;
}
