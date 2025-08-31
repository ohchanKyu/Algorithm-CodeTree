#include <bits/stdc++.h>

using namespace std;

int n;
int r, c;
int a[100][100];

// 상 하 좌 우 
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

struct Element{
    int x,y,d;
};
bool cmp(const Element &a, const Element &b){
    return a.d < b.d;
}
void go(int x,int y){

    cout << a[x][y] << " ";
    vector<Element> tmp;
    for(int d=0;d<4;d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (a[nx][ny] > a[x][y]) tmp.push_back({ nx,ny,d });
    }
    if (tmp.size() == 0) return;

    sort(tmp.begin(),tmp.end(),cmp);
    go(tmp[0].x,tmp[0].y);
}
int main() {
    cin >> n >> r >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    go(--r,--c);

    return 0;
}
