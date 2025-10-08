#include <bits/stdc++.h>

using namespace std;

int N,x,y;
vector<pair<int,int>> v;
int ret;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    
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