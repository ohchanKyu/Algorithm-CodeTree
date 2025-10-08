#include <bits/stdc++.h>

using namespace std;

int N,x,y;
vector<pair<int,int>> v;
int ret;

bool cmp(pair<int,int> &a,pair<int,int> &b){
    
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);
    
    int l = 0;
    for(int i=0;i<N;i++){
        tie(x,y) = v[i];
        if (l < x){
            ret++;
            l = y;
        }
    }
    cout << ret;
    return 0;
}