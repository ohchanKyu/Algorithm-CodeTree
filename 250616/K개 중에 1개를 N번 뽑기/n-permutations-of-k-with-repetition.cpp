#include <iostream>
#include <vector>

using namespace std;

int K, N;

void dfs(int index,vector<int> v){
    
    if (index == N){
        for(int a : v){
            cout << a << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=K;i++){
        v.push_back(i);
        dfs(index+1,v);
        v.pop_back();
    }
}
int main() {

    cin >> K >> N;
    vector<int> v;
    dfs(0,v);

    return 0;
}
