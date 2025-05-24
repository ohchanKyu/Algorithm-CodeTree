#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<bool> visited;
void dfs(int start);

int main() {

    cin >> n >> m;
    v.resize(n+1);
    visited.resize(n+1);
    std::fill(visited.begin(),visited.end(),false);
    for (int i = 0; i < m; i++) {
       int s,e;
       cin >> s >> e;
       v[s].push_back(e);
       v[e].push_back(s);
    }
    // Please write your code here.
    dfs(1);
    int cnt = 0;
    for(int i=2;i<=n;i++){
        if (visited[i]) cnt += 1;
    }
    cout << cnt;
    return 0;
}

void dfs(int start){
    if (visited[start]) return;

    visited[start] = true;
    for(int next : v[start]){
        dfs(next);
    }
}
