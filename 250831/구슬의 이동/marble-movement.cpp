#include <bits/stdc++.h>

using namespace std;

int n, m, t, k;
int r[2500], c[2500];
char d[2500];
int velo[2500];

struct Element {
    int id,x,y,d,v;
};
// 위 오른 아래 왼
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
vector<Element> visited[54][54];
vector<Element> v;

bool cmp(const Element &a, const Element &b){

    if (a.v == b.v) return a.id > b.id;
    return a.v > b.v;
}

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
        int v = e.v;
        int t = 0;

        while(t != v){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n){
                dir = (dir + 2) % 4;
                t--;
            }else{
                x = nx;
                y = ny;
            }
            t++;
        }
        visited[x][y].push_back({ id,x,y, dir, v});
    }

    v.clear();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (visited[i][j].size() == 0) continue;
            if (visited[i][j].size() <= k){
                for(Element a : visited[i][j]){
                    v.push_back(a);
                }
            }else{
                sort(visited[i][j].begin(),visited[i][j].end(),cmp);
                for(int aa=0;aa<k;aa++){
                    v.push_back(visited[i][j][aa]);
                }
            }
            
        }
    }
}


int main() {
    cin >> n >> m >> t >> k;

    for (int i = 0; i < m; i++) {
        // 위치, d는 방향, v는 속도
        cin >> r[i] >> c[i] >> d[i] >> velo[i];
        int dir;
        if (d[i] == 'U') dir = 0;
        else if (d[i] == 'D') dir = 2;
        else if (d[i] == 'R') dir = 1;
        else dir = 3;
        v.push_back({ i+1, --r[i],--c[i],dir, velo[i] });
    }

    while(t--){
        move();
    }
    cout << v.size();
    return 0;
}
