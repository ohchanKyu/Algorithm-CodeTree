#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m, k;
int arr1[100000];
int arr2[100000];

struct Compare {

    bool operator()(const tuple<int,int,int,int> &a, const tuple<int,int,int,int> &b) const {
        return get<0>(a) > get<0>(b);
    }
};
int main() {

    cin >> n >> m >> k;
    // A+B, A, B, B idx
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>,Compare> pq;
    
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    sort(arr1,arr1+n);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    sort(arr2,arr2+m);
    for(int i=0;i<n;i++){
        pq.push(make_tuple(arr1[i] + arr2[0], arr1[i], arr2[0],0));
    }

    int ans;
    while(k--){
        int x,y,idx;
        tie(ans,x,y,idx) = pq.top();
        if (idx >= m) break;
        pq.pop();
        pq.push(make_tuple(x+arr2[idx+1],x, arr2[idx+1], idx+1));
    }
    cout << ans;
    return 0;
}
