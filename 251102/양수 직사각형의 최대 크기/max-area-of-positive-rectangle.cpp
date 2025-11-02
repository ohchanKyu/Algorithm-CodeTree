#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[20][20];
int ret;

void go(int x,int y,int r,int c){

    for(int i=x;i<x+r;i++){
        for(int j=y;j<y+c;j++){
            if (i < 0 || j < 0 || i >= n || j >= m) return;
            if (grid[i][j] <= 0) return;
        }
    }
    ret = max(ret, r * c);
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
            for(int r=1;r<=n;r++){
                for(int c=1;c<=m;c++){
                    go(i,j,r,c);
                }
            }
        }
    }
    cout << ret;
    return 0;
}
