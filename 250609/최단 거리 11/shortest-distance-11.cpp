#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

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
    // 역으로 B부터 진행
    mdist[B] = 0;
    pq.push(edge(0,B));

    while(!pq.empty()){
        edge now = pq.top(); pq.pop();
        int now_x = now.second;
        if (visited[now_x]) continue;
        visited[now_x] = true;

        for(edge next : graph[now_x]){
            int nx = next.first;
            int weight = next.second;
            if (mdist[nx] > mdist[now_x] + weight){
                mdist[nx] = mdist[now_x] + weight;
                pq.push(edge(mdist[nx],nx));
            }
        }
    }
    cout << mdist[A] << "\n";

    int x = A;
    cout << x << " ";
    while(x != B){
        // A -> i ... -> B 까지 역추적
        bool found = false;
        // mdist에서는 B -> i ... -> A 경로가 존재.
        for(int i=1;i<=n && !found;i++){
            // graph[i]는 i에서 다른 정점으로 가는것을 뜻함
            for(edge next : graph[i]){
                int nx = next.first; // x
                int weight = next.second; // i -> x로 가는 weight
                if (nx == x && mdist[i] + weight == mdist[x]){
                    x = i;
                    found = true;
                    break;
                }
            }
        }
        cout << x << " ";
    }
    return 0;
}
