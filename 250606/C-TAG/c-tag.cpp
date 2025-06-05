#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m;
string A[500];
string B[500];
void dfs(int depth,int start,vector<int> v);
void check(vector<int> v);
long long ans = 0;

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    vector<int> v;
    dfs(0,0,v);
    cout << ans;
    return 0;
}

void dfs(int depth,int start,vector<int> v){
    
    if (depth == 3){
        check(v);
        return;
    }
    for(int i=start;i<m;i++){
        v.push_back(i);
        dfs(depth+1,i+1,v);
        v.pop_back();
    }
}

void check(vector<int> v){
    
    unordered_set<string> Aset;
    vector<string> checklist;

    for(int i=0;i<n;i++){
        string target =  "";
        string target2 = "";

        for(int idx : v){
            target += A[i][idx];
            target2 += B[i][idx];
        }
        checklist.push_back(target2);
        Aset.insert(target);
    }
    
    bool isSeperate = true;
    for(string s : checklist){
        if (Aset.find(s) != Aset.end()) isSeperate = false;
    }
    if (isSeperate) ans += 1;
}