#include <bits/stdc++.h>

using namespace std;

int N;
char grid[20][20];
pair<int,int> s;
pair<int,int> e;
int ret = 987654321;

struct coin{
    int x,y,val;
};
vector<coin> coins;
bool cmp(const coin &a,const coin &b){
    return a.val < b.val;
}

int calDist(int x1,int y1,int x2,int y2){
    return abs(x1-x2) + abs(y1-y2);
}
void go(int idx,int start,vector<int> &v){
    if (idx == 3){
        int tmp = 0;
        tmp += calDist(s.first,s.second,coins[v[0]].x,coins[v[0]].y);
        for(int i=0;i<v.size()-1;i++){
            tmp += calDist(coins[v[i]].x,coins[v[i]].y,coins[v[i+1]].x,coins[v[i+1]].y);
        }
        tmp += calDist(coins[v[2]].x,coins[v[2]].y, e.first, e.second);
        ret = min(ret,tmp);
        return;
    }
    for(int i=start;i<coins.size();i++){
        v.push_back(i);
        go(idx+1,i+1,v);
        v.pop_back();
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') continue;
            else if (grid[i][j] == 'S') s = {i,j};
            else if (grid[i][j] == 'E') e = {i,j};
            else coins.push_back({i,j,grid[i][j] - '0'});
        }
    }
    if (coins.size() < 3){
        cout << -1;
        return 0;
    }
    sort(coins.begin(),coins.end(),cmp);
    vector<int> tmp;
    go(0,0,tmp);
    cout << ret;
    

    return 0;
}
