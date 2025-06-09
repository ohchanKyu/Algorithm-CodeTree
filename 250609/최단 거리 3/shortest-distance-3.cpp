#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int n, m;
int A, B;
typedef pair<int,int> edge;

int main() {

    cin >> n >> m;
    vector<vector<edge>> graph(n+1);
    vector<int> mdist(n+1,INT_MAX);
    vector<bool> visited(n+1,false);
    priority_queue<edge,vector<edge>,greater<edge>> pq;

    for (int i = 0; i < m; i++) {
        int s,e,v;
        cin >> s >> e >> v;
        graph[s].push_back(edge(e,v));
        graph[e].push_back(edge(s,v));
    }

    cin >> A >> B;

    mdist[A] = 0;
    pq.push(edge(0,A));
    
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
    cout << mdist[B];

    return 0;
}
