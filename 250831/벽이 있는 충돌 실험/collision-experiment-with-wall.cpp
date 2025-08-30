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
vector<Element> A[54][54];
vector<Element> v;

// 위쪽 오른쪽 아래 왼쪽
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

void move(){

   unordered_map<int, vector<Element>> mp;
    for(auto &it : v){
        int x = it.x;
        int y = it.y;
        int dir = it.d;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N){
            dir = (dir + 2) % 4;
            nx = x;
            ny = y;
        }
        mp[nx * N + ny].push_back({nx, ny, dir});
    }
    v.clear();
    for (auto &it : mp) {
        if (it.second.size() == 1) {
            v.push_back(it.second[0]);
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
