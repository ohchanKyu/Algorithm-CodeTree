#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int n, k;
int arr[100000];

struct Compare {

    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        if (a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    }
};

int main() {
    
    unordered_map<int,int> m;
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> q;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]] += 1;
    }
    for(auto& [key,value] : m){
        q.push(make_pair(value,key));
    }
    for(int i=0;i<k;i++){
        cout << q.top().second << " ";
        q.pop();
    }
    return 0;
}
