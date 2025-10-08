#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
typedef long long ll;

int N,A,B;
int grid[34][34];
ll dist[34][34];

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
string str;
ll ret;

void dijstra(int x,int y){

    fill(&dist[0][0],&dist[0][0] + 34 * 34,INF);
    priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> pq;
    pq.push({0,{x,y}});
    dist[x][y] = 0;

    while(pq.size()){
        int sx = pq.top().second.first;
        int sy = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();
        if (cost != dist[sx][sy]){
            continue;
        }
        for(int d=0;d<4;d++){
            int nx = sx + dx[d];
            int ny = sy + dy[d];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            int nCost = (grid[sx][sy] == grid[nx][ny]) ? A : B;
            if (dist[nx][ny] > dist[sx][sy] + nCost){
                dist[nx][ny] = dist[sx][sy] + nCost;
                pq.push({dist[nx][ny],{nx,ny}});
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ret = max(ret,dist[i][j]);
        }
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> A >> B;
    for(int i=0;i<N;i++){
        cin >> str;
        for(int j=0;j<N;j++){
            if (str[j] == '('){
                grid[i][j] = 0;
            }else grid[i][j] = 1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dijstra(i,j);
        }
    }

    cout << ret;
    return 0;
}