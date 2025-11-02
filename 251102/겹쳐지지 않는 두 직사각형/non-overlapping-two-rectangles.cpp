#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[5][5];
int visited[5][5];
int ret = -987654321;
int tmp;

bool go(int x,int y,int r,int c){

    tmp = 0;
    for(int i=x;i<x+r;i++){
        for(int j=y;j<y+c;j++){
            if (i < 0 || j < 0 || i >= n || j >= m) return false;
            visited[i][j] = 1;
            tmp += grid[i][j];
        }
    }
    return true;
}
void cal(int x,int y,int r,int c){
    
    int tmp2 = tmp;
    for(int i=x;i<x+r;i++){
        for(int j=y;j<y+c;j++){
            if (i < 0 || j < 0 || i >= n || j >= m) return;
            if (visited[i][j]) return;
            tmp2 += grid[i][j];
        }
    }
    ret = max(ret,tmp2);
}
void go2(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (visited[i][j]) continue;
            for(int r=1;r<=n;r++){
                for(int c=1;c<=m;c++){
                    cal(i,j,r,c);
                }
            }
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
            for(int r=1;r<=n;r++){
                for(int c=1;c<=m;c++){
                    memset(visited,0,sizeof(visited));
                    if(go(i,j,r,c)){
                        go2();
                    }
                }
            }
        }
    }
    cout << ret;

    return 0;
}
