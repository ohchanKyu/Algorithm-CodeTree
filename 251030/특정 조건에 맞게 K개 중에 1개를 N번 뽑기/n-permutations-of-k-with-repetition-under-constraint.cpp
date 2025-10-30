#include <bits/stdc++.h>

using namespace std;

int K, N;
int cnt[8];
set<string> s;

bool check(vector<int> &v){

    for(int i=0;i<N-2;i++){
        if (v[i] == v[i+1] && v[i+1] == v[i+2]) return false;        
    }
    return true;
}

void go(int idx,vector<int> &v){

    if (idx == N){
        if (check(v)){
            string tmp = "";
            for(int a : v){
                tmp += to_string(a) + " ";
            }
            s.insert(tmp);    
        }
        return;
    }
    for(int i=1;i<=K;i++){
        v.push_back(i);
        go(idx+1,v);
        v.pop_back();
    }
}
int main() {

    cin >> K >> N;
    vector<int> v;
    go(0,v);
    for(auto it = s.begin();it != s.end();it++){
        cout << *it << "\n";
    }

    return 0;
}
