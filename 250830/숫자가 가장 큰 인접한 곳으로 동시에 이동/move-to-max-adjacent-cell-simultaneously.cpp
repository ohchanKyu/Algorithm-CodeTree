#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int a[20][20];
int r[400], c[400];
// 상 하 좌 우
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
vector<pair<int,int>> v;

struct bead{
    int x,y,v,d;
};
bool cmp(const bead &a, const bead &b){
    if (a.v == b.v){
        return a.d < b.d;
    }
    return a.v > b.v;
}
void move(){
   
    map<pair<int,int>,int> mp;
    for(auto it : v){
        int x = it.first;
        int y = it.second;
        vector<bead> vv;
        for(int d=0;d<4;d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            vv.push_back({ nx,ny, a[nx][ny],d });
        }
        sort(vv.begin(),vv.end(),cmp);
        mp[{vv[0].x,vv[0].y}] += 1;
    }
    v.clear();
    for(auto it : mp){
        if (it.second > 1) continue;
        v.push_back({ it.first.first, it.first.second });
    }
}
int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i];
        v.push_back({--r[i],--c[i]});
    }
    while(t--){
        move();
    }
    cout << v.size();
    return 0;
}
