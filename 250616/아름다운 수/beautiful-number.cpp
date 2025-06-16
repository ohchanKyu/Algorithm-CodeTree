#include <iostream>

using namespace std;

int n;
int count = 0;

void dfs(int index){
    
    if (index > n) return;
    if (index == n){
        count += 1;
        return;
    }
    for(int i=1;i<=4;i++){
        dfs(index + i);
    }
}

int main() {

    cin >> n;
    dfs(0);
    cout << count;
    return 0;
}
