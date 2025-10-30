#include <bits/stdc++.h>

using namespace std;

int N,M,a,b;
vector<int> org;
vector<pair<int,int>> ladder;
int grid[20][20];
int ret = 987654321;

vector<int> check(){

    vector<int> v;
    v.push_back(-1);
    for(int i=1;i<=M;i++){
        int x = 0;
        int y = i;
        while(true){
            int nx = x + 1;
            if (nx > N) break;
            int ny;
            if (grid[nx][y]){
                ny = y + 1;
            }else if (grid[nx][y-1]){
                ny = y - 1;
            }else ny = y;
            x = nx;
            y = ny;
        }
        v.push_back(y);
    }
    return v;
}

void go(int cnt, int nums){

    if (cnt > ret) return;
    if (nums == (1 << M) - 1) return;
    
    vector<int> tmp = check();
    bool isPossible = true;
    for(int i=0;i<tmp.size();i++){
        if (tmp[i] != org[i]){
            isPossible = false;
            break;
        }
    }
    if (isPossible) ret = min(ret,cnt);

    for(int i=0;i<ladder.size();i++){
        if (nums & (1 << i)) continue;
        auto [x,y] = ladder[i];
        grid[x][y] = 1;
        go(cnt+1,nums | (1 << i));
        grid[x][y] = 0;
    }
}

int main() {

    cin >> M >> N;
    for(int i=0;i<N;i++){
        cin >> a >> b;
        grid[b][a] = 1;
        ladder.push_back({b,a});
    }
    org = check(); 
    for(auto it : ladder){
        grid[it.first][it.second] = 0;
    }
    go(0,0);
    cout << ret;
    return 0;
}
