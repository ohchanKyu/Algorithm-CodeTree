#include <bits/stdc++.h>

using namespace std;

int N,s,e,val;
struct alba{
    int s,e,val;
};
vector<alba> v;
int ret;
int dp[1004];


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s >> e >> val;
        v.push_back({s,e,val});
    }
    for(int i=0;i<N;i++){
        int curVal = v[i].val;
        for(int j=0;j<i;j++){
            if (v[j].e < v[i].s){
                dp[i] = max(dp[i],dp[j] + curVal);
            }
        }
        dp[i] = max(dp[i],curVal);
        ret = max(ret,dp[i]);
    }
    cout << ret;
    return 0;
}