#include <bits/stdc++.h>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;


const int dirV[2][2][4] = {
    {{-1,-1,1,1},{1,-1,-1,1}},
    {{-1,-1,1,1},{-1,1,1,-1}}
};

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
int getLen(int d,int dir){
    int len = 0;
    if (dir){
        len = (d & 1) ? m1 : m2;
    }else{
        len = (d & 1) ? m2 : m1;
    }
    return len;
}
int main() {

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    r--;
    c--;
    
    int d = 0;
    int tmp = grid[r][c];
    int x = r;
    int y = c;
    while(true){
        if (d == 4) break;
        int len = getLen(d,dir);
        for(int i=1;i<=len;i++){
            int nx = x + dirV[dir][0][d];
            int ny = y + dirV[dir][1][d];
            int cur = grid[nx][ny];
            grid[nx][ny] = tmp;
            tmp = cur;
            x = nx;
            y = ny;
        }
        d += 1;
    }   
    print();
    return 0;
}
