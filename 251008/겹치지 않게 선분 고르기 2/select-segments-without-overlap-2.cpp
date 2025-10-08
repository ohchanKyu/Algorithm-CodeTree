#include <bits/stdc++.h>

using namespace std;

int N,x,y;
vector<pair<int,int>> v;
int visited[1004];
int dp[1004];

int go(int idx){

    if (idx == N) return 0;

    int &ret = dp[idx];
    if (ret != -1) return ret;
    
    ret = 0;
    int s = v[idx].first;
    int e = v[idx].second;
    bool isPossible = true;
    for(int i=s;i<=e;i++){
        if (visited[i]){
            isPossible = false;
            break;
        }
    }
    if (isPossible){
        for(int i=s;i<=e;i++){
            visited[i] = 1;
        }
        ret = max(ret,go(idx+1) + 1);
        for(int i=s;i<=e;i++){
            visited[i] = 0;
        }
    }
    ret = max(ret,go(idx+1));
    return ret;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    memset(dp,-1,sizeof(dp));
    cout << go(0);
    return 0;
}