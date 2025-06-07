#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> coord;
const int MAX_N = 100000;
int n, m;
int x[MAX_N], y[MAX_N];

struct compare{

    bool operator()(const coord &a,const coord &b) const {
        if (a.first + a.second == b.first == b.second){
            if (a.first == b.first) return a.second > b.second; 
            return a.first > a.second;
        }
        return a.first + a.second > b.first + b.second;
    }
};

int main() {

    cin >> n >> m;
    priority_queue<coord,vector<coord>,compare> q;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        q.push(coord(x[i],y[i]));
    }
    for(int i=0;i<m;i++){
        coord now = q.top();
        q.pop();
        int nx = now.first + 2;
        int ny = now.second + 2;
        q.push(coord(nx,ny));
    }
    cout << q.top().first << " " << q.top().second;
    return 0;
}
