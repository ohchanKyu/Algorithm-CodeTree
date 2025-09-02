#include <bits/stdc++.h>

using namespace std;

int n, m;
int numbers[100];
stack<int> stk;
int visited[100];

vector<pair<int,int>> vv;
vector<int> v;

void print(){
    cout << v.size() << "\n";
    for(int a : v){
        cout << a << "\n";
    }
}
int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        v.push_back(numbers[i]);
    }
    while(true){
        
        int v_size = (int) v.size();
        fill(visited,visited+100,0);
        vv.clear();
        for(int i=0;i< v_size ;i++){
            int cnt = 0;
            for(int j=i;j<v_size;j++){
                if (v[i] == v[j]){
                    cnt++;
                }else break;
            }
            if (cnt >= m) vv.push_back({ i, i + cnt - 1});
        }
        if (vv.size() == 0) break;
        for(auto it : vv){
            for(int i =it.first;i<=it.second;i++){
                visited[i] = 1;
            }
        }
        vector<int> tmp;
        for(int i=0;i<v_size;i++){
            if (visited[i]) continue;
            tmp.push_back(v[i]);
        }
        v = tmp;
    }

    print();
    
    return 0;
}
