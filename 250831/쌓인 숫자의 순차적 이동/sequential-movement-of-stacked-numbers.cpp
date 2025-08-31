#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[20][20];
int move_nums[100];
struct Element{
    int x,y,value;
};
deque<Element> adj[24][24];
unordered_map<int,pair<int,int>> mp;

const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};

void adjustGridValue(int x,int y){

    deque<Element> dq;
    if (adj[x][y].size() == 0){
        grid[x][y] = 0;
        return;
    }
    int ret = 0;
    while(adj[x][y].size()){
        ret = max(ret, adj[x][y].back().value);
        dq.push_front(adj[x][y].back());
        adj[x][y].pop_back();
    }
    grid[x][y] = ret;
    adj[x][y] = dq;
}
void move(int target){
    
    int x,y;
    tie(x,y) = mp[target];
    int maxV = 0;
    int tx = 0;
    int ty = 0;
    for(int d=0;d<8;d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (maxV < grid[nx][ny]){
            maxV = grid[nx][ny];
            tx = nx;
            ty = ny;
        }
    }
    // Move
    if (maxV != 0){
        deque<Element> tmp;
        while(adj[x][y].size()){
            Element e = adj[x][y].front();
            adj[x][y].pop_front();
            int x = e.x;
            int y = e.y;
            int value = e.value;
            tmp.push_front({x,y,value});
            mp[value] = {tx,ty};
            if (value == target) break;
        }
        adjustGridValue(x,y);
        while(tmp.size()){
            adj[tx][ty].push_front(tmp.front());
            grid[tx][ty] = max(grid[tx][ty],tmp.front().value);
            tmp.pop_front();
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            mp[grid[i][j]] = {i,j};
            adj[i][j].push_back({ i,j, grid[i][j]});
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> move_nums[i];
        move(move_nums[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (adj[i][j].size() == 0) cout << "None\n";
            else {
                while(adj[i][j].size()){
                    int val = adj[i][j].front().value;
                    adj[i][j].pop_front();
                    cout << val << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
