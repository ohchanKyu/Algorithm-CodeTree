#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

int n, m;
int x[20], y[20];
int ret = 987654321;

int calDist(int x1, int y1, int x2, int y2){
    int a = abs(x1-x2);
    int b = abs(y1-y2);
    return a * a + b * b;
}

void go(int idx,int start,vector<int> &v){

    if (idx == m){
        int dist = 0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                int x1 = x[v[i]];
                int y1 = y[v[i]];
                int x2 = x[v[j]];
                int y2 = y[v[j]];
                dist = max(dist,calDist(x1,y1,x2,y2));
            }
        }
        ret = min(ret,dist);
        return;
    }
    for(int i=start;i<n;i++){
        v.push_back(i);
        go(idx+1,i+1,v);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> tmp;
    go(0,0,tmp);
    cout << ret;

    return 0;
}
