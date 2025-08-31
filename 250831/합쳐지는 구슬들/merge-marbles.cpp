#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int r[2500], c[2500];
char d[2500];
int w[2500];


struct Element {
    int id,x,y,d,w;
};
vector<Element> v;
vector<Element> visited[54][54];
// 위 오른 아래 왼
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

void clear(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j].clear();
        }
    }
}
void move(){
    
    clear();
    for(Element &e : v){
        int id = e.id;
        int x = e.x;
        int y = e.y;
        int dir = e.d;
        int weight = e.w;

        int nx = x + dx[dir];
        int ny = y  +dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n){
            dir = (dir + 2) % 4;
            nx = x;
            ny = y;
        }
        visited[nx][ny].push_back({ id,nx,ny,dir,weight });
    }
    v.clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (visited[i][j].size() == 0) continue;
            if (visited[i][j].size() == 1){
                v.push_back(visited[i][j][0]);
            }else{
                int maxDir = 0;
                int sumWeight = 0;
                int maxNum = 0;
                for(Element &e : visited[i][j]){
                    sumWeight += e.w;
                    maxDir = max(maxDir,e.d);
                    maxNum = max(maxNum, e.id);
                }
                v.push_back({ maxNum, i,j, maxDir, sumWeight});
            }
        }
    }
}
int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i] >> d[i] >> w[i];
        int dir;
        if (d[i] == 'U') dir = 0;
        else if (d[i] == 'D') dir = 2;
        else if (d[i] == 'R') dir = 1;
        else dir = 3;
        v.push_back({ i+1,--r[i],--c[i],dir,w[i]});
    }

    while(t--){
        move();
    }
    int maxV = 0;
    for(Element &e : v){
        maxV = max(maxV , e.w);
    }
    cout << v.size() << " " << maxV;
    return 0;
}
