#include <bits/stdc++.h>

using namespace std;

int n;
int ret = 987654321;
int grid[100][100];
const int dx[] = {0,1};
const int dy[] = {1,0};

void go(int x,int y, vector<int> &v){

    if (x == n-1 && y == n-1){
        vector<int> tempV = v;
        sort(tempV.begin(),tempV.end());
        int tmp = abs(tempV[0] - tempV[tempV.size()-1]);
        ret = min(ret, tmp);
        return;
    }
    for(int d=0;d<2;d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        v.push_back(grid[nx][ny]);
        go(nx,ny,v);
        v.pop_back();
    }
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> tmp;
    tmp.push_back(grid[0][0]);
    go(0,0,tmp);
    cout << ret;


    return 0;
}
