#include <bits/stdc++.h>

using namespace std;

int n, m;
int A[20];
int ret;

void combi(int idx,int start,vector<int> &v){
    
    if (idx == m){
        int ans = 0;
        for(int i : v){
            ans ^= A[v[i]];
        }
        ret = max(ret,ans);
        return;
    }
    for(int i=start;i<n;i++){
        v.push_back(i);
        combi(idx+1,i+1,v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> tmp;
    combi(0,0,tmp);
    cout << ret;

    return 0;
}