#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[200][200];
int ret;

vector<vector<pair<int,int>>> coord = {
    {{0,0},{1,0},{1,1}},
    {{0,0},{0,1},{0,2}},
};
// 90 -> ( -y, x )
// 180 -> ( -x, -y )
// 270 -> ( y, -x )

bool is_range(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
pair<int,int> conversion(int d,int x,int y){
    if (d == 0) return {x,y};
    else if (d == 1) return {-y,x};
    else if (d == 2) return {-x,-y};
    else return {y,-x};
}

void check(int x,int y){

    for(int i=0;i<coord.size();i++){
        vector<pair<int,int>> v = coord[i];
        for(int d=0;d<4;d++){
            int tmp = 0;
            bool isRight = true;
            for(auto it : v){
                auto [tx,ty] = it;
                tie(tx,ty) = conversion(d,tx,ty);
                tx += x;
                ty += y;
                if (!is_range(tx,ty)){
                    isRight = false;
                    break;
                }
                tmp += grid[tx][ty];
            }
            if (isRight) ret = max(ret,tmp);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check(i,j);
        }
    }
    cout << ret;

    return 0;
}
