#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

ll N,M,X;
ll s,e,l,c;
ll dist[504];

struct Element{
    ll e,c,l;
};
vector<Element> adj[504];

struct dijElement{
    ll s,c,d;
};

struct Compare{
    bool operator()(const dijElement &a,const dijElement &b){
        return a.d > b.d;
    }
};

ll ret = INF;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> X;
    for(ll i=0;i<M;i++){
        cin >> s >> e >> l >> c;
        adj[s].push_back({e,c,l});
        adj[e].push_back({s,c,l});
    }

    priority_queue<dijElement,vector<dijElement>,Compare> pq;
    fill(dist,dist+504,INF);

    dist[1] = 0;
    pq.push({ 1,1000001,0 });
    
    while(pq.size()){
        ll s = pq.top().s;
        ll d = pq.top().d;
        ll c = pq.top().c;
        pq.pop();
        if (dist[s] != d){
            continue;
        }
        for(auto it : adj[s]){
            ll ns = it.e;
            ll nl = it.l;
            ll nc = min(it.c,c);
            ll new_dist = (d + nl) + X / nc;
            if (ns != N){
                if (dist[ns] > dist[s] + nl){
                    dist[ns] = dist[s] + nl;
                    pq.push({ ns,nc,dist[ns]});
                }
            }else if (dist[ns] > new_dist){
                dist[ns] = new_dist;
            }
        }
    }
    cout << dist[N];
    return 0;
}