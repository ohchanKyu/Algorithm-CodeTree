#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int nums[12];
int com[5];
int ret;

int cal(vector<int> &v){

    memset(com,0,sizeof(com));

    int cnt = 0;
    for(int i=0;i<n;i++){
        int dist = nums[i];
        int cur = v[i];

        if (com[cur] == m-1) continue;
        com[cur] = min(m-1, com[cur] + dist);
    }
    for(int i=1;i<=k;i++){
        if (com[i] == m-1) cnt++;
    }
    return cnt;
}
void go(int idx, vector<int> &v){

    if (idx == n){
        ret = max(ret,cal(v));
        return;
    }
    for(int i=1;i<=k;i++){
        v.push_back(i);
        go(idx+1,v);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> v;
    go(0,v);
    cout << ret;

    return 0;
}
