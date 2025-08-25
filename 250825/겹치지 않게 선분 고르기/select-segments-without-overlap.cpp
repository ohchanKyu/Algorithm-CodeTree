#include <bits/stdc++.h>

using namespace std;

int n;
int x1[15], x2[15];
int maxV = 0;
int visited[15];

int cal(vector<int> &v){

    fill(visited,visited + 15,false);
    int cnt = 0;
    for(int i=0;i<v.size();i++){
        if (!v[i]) continue;
        int l = x1[i];
        int r = x2[i];
        for(int i=l;i<=r;i++){
            if (visited[i]) return -1;
            visited[i] = 1;
        }
        cnt++;
    }
    return cnt;
}
void go(int idx,vector<int> &v){
    
    if (idx == n){
        maxV = max(maxV, cal(v));
        return;
    }
    v.push_back(0);
    go(idx+1,v);
    v.pop_back();

    v.push_back(1);
    go(idx+1,v);
    v.pop_back();
}
int main() {
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }
    vector<int> idx;
    go(0,idx);
    cout << maxV;
    return 0;
}
