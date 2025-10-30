#include <bits/stdc++.h>

using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;
int ret;

const int dx[] = {-1,-1,0,1,1,1,0,-1};
const int dy[] = {0,1,1,1,0,-1,-1,-1};

bool is_range(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}

void go(int x,int y,int cnt){
    
    ret = max(ret,cnt);
    int target = num[x][y];
    int dir = move_dir[x][y];

    while(true){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!is_range(nx,ny)) break;
        if (num[nx][ny] > target) go(nx, ny, cnt+1);
        x = nx;
        y = ny;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> move_dir[i][j];
            move_dir[i][j]--;
        }
    }
    cin >> r >> c;
    r--;
    c--;
    go(r,c,0);
    cout << ret;


    return 0;
}
