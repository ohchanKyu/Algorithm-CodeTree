#include <bits/stdc++.h>
#define y1 nahc

using namespace std;

int n, m, c;
int weight[10][10];
int maxV;
int visited[10][10];
int temp[17][17];
int dp[34];
// 8
// 10 6 5 3
int cal(vector<pair<int,int>> &v){

    memset(temp,0,sizeof(temp));
    memset(dp,0,sizeof(dp));
    int x1 = v[0].first;
    int y1 = v[0].second;
    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;

    for(int i=0;i<m;i++){
        temp[x1][y1+i] = 1;
        if (y1 + i >= n) continue;
        int t1 = weight[x1][y1+i];
        v1.push_back({t1 * t1 ,t1});
    }
    int x2 = v[1].first;
    int y2 = v[1].second;
    for(int i=0;i<m;i++){
        if (temp[x2][y2+i]) return -1;    
        if (y2 + i >= n) continue;
        int t2 = weight[x2][y2+i];
        v2.push_back({t2 * t2, t2});
    }
    int sum = 0;
    for(int i=0;i<v1.size();i++){
        int w = v1[i].second;
        int value = v1[i].first;
        for(int j=c;j>=w;j--){
            dp[j] = max(dp[j], dp[j-w] + value);
        }
    }
    sum += dp[c];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<v2.size();i++){
        int w = v2[i].second;
        int value = v2[i].first;
        for(int j=c;j>=w;j--){
            dp[j] = max(dp[j], dp[j-w] + value);
        }
    }
    sum += dp[c];
    return sum;
}
void go(int idx,vector<pair<int,int>> &v){

    if (idx == 2){
        maxV = max(maxV,cal(v));
        return; 
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (visited[i][j]) continue;
            visited[i][j] = 1;
            v.push_back({i,j});
            go(idx+1, v);
            v.pop_back();
            visited[i][j] = 0;
        }
    }
}
int main() {

    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }
    // 최대 100개의 좌표
    vector<pair<int,int>> v;
    go(0,v);
    cout << maxV;
    return 0;
}