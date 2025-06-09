#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m;
int a, b, c;
typedef pair<int,int> edge;
vector<vector<edge>> graph;
vector<int> mdist;
vector<bool> visited;
vector<int> ans;
void shortest_path(int start);

int main() {

    cin >> n >> m;
    cin >> a >> b >> c;

    graph.resize(n+1); visited.resize(n+1); mdist.resize(n+1);
    ans.resize(n+1);
    std::fill(ans.begin(),ans.end(),INT_MAX);
    for (int i = 0; i < m; i++) {
       int s,e,v;
       cin >> s >> e >> v;
       graph[s].push_back(edge(e,v));
       graph[e].push_back(edge(s,v));
    }
    shortest_path(a);
    shortest_path(b);
    shortest_path(c);
    int maxV = 0;
    for(int i=1;i<=n;i++){
        if (ans[i] != INT_MAX){
            maxV = max(maxV,ans[i]);
        }
    }
    cout << maxV << "\n";
    return 0;
}
void shortest_path(int start){
    
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    std::fill(visited.begin(),visited.end(),false);
    std::fill(mdist.begin(),mdist.end(),INT_MAX);

    mdist[start] = 0;
    pq.push(edge(0,start));

    while(!pq.empty()){
        edge now = pq.top(); pq.pop();
        int x = now.second;
        if (visited[x]) continue;
        visited[x] = true;

        for(edge next : graph[x]){
            int nx = next.first;
            int weight = next.second;
            if (mdist[nx] > mdist[x] + weight){
                mdist[nx] = mdist[x] + weight;
                pq.push(edge(mdist[nx],nx));
            }
        }
    }
    for(int i=1;i<=n;i++){
        if (i != a && i != b && i != c){
            ans[i] = min(ans[i],mdist[i]);
        }
    }
}
