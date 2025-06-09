#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int,int> edge;
int n, m;

int main() {

    cin >> n >> m;

    vector<vector<edge>> graph;
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    vector<bool> visited(n+1,false);
    vector<int> mdist(n+1,INT_MAX);

    graph.resize(n+1);
    graph.resize(n+1);

    for (int i = 0; i < m; i++) {
       int s,e,v;
       cin >> s >> e >> v;
       graph[s].push_back(edge(e,v));
    }

    mdist[1] = 0;
    pq.push(edge(0,1));

    while(!pq.empty()){
        
        edge now = pq.top();
        pq.pop();
        int now_x = now.second;
        if (visited[now_x]) continue;
        visited[now_x] = true;

        for(edge next : graph[now_x]){
            int next_x = next.first;
            int weight = next.second;
            if (mdist[next_x] > mdist[now_x] + weight){
                mdist[next_x] = mdist[now_x] + weight;
                pq.push(edge(mdist[next_x],next_x));
            }
        }
    }

    for(int i=2;i<=n;i++){
        if (mdist[i] == INT_MAX) cout << -1 << "\n";
        else cout << mdist[i] << "\n";
    }
    return 0;
}
