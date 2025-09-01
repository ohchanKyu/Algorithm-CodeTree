#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int x,y;
char d[1000];
int p[1000];
int grid[104][104];

// 상 하 우 좌
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};
map<char,int> mp;

void printResult(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {

    cin >> N >> M >> K;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        grid[--x][--y] = 2;
    }
    mp['U'] = 0;
    mp['D'] = 1;
    mp['R'] = 2;
    mp['L'] = 3;    

    int ret = 0;
    x = 0;
    y = 0;
    grid[x][y] = 1;
    deque<pair<int,int>> dq;
    dq.push_front({ x,y });

    for (int i = 0; i < K; i++){
        cin >> d[i] >> p[i];
        int dir = mp[d[i]];

        for(int t=0;t<p[i];t++){
            ret++;
            tie(x,y) = dq.front();
            // 뱀의 머리 다음 좌표
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            // 벗어난 경우
            if (nx < 0 || ny < 0 || nx >= N || ny >= N){
                cout << ret;
                exit(0);
            }
            // 사과인 경우
            if (grid[nx][ny] == 2){
                if (grid[nx][ny] == 1){
                    cout << ret;
                    exit(0);
                }
                dq.push_front({nx,ny});
                grid[nx][ny] = 1;
            // 사과가 없는 경우
            }else{
                tie(x,y) = dq.back();
                dq.pop_back();
                grid[x][y] = 0;
                if (grid[nx][ny] == 1){
                    cout << ret;
                    exit(0);
                }
                grid[nx][ny] = 1;
                dq.push_front({nx,ny});
            }
        }
    }
    cout << ret;
    return 0;
}
