#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int N, M;
typedef pair<int,int> edge;

int main() {
    
    cin >> N >> M;
    vector<vector<edge>> graph;
    vector<bool> visited(N+1,false);
    vector<int> mdist(N+1,INT_MAX);
    priority_queue<edge,vector<edge>,greater<edge>> pq;
    graph.resize(N+1);
    for (int k = 0; k < M; k++) {
        int s,e,v;
        cin >> s >> e >> v;
        graph[e].push_back(edge(s,v));
    }

    mdist[N] = 0;
    pq.push(edge(0,N));
    while(!pq.empty()){
        edge now = pq.top(); pq.pop();
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
    int maxV = 0;
    for(int i=1;i<=N-1;i++){
        maxV = max(mdist[i],maxV);
    }
    cout << maxV << "\n";
    return 0;
}
