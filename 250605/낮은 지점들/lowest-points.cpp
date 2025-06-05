#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int x[100000], y[100000];
long long ans = 0;

int main() {

    cin >> n;

    unordered_map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        if (m.find(x[i]) == m.end()){
            m[x[i]] = y[i];
        }else{
            if (y[i] < m[x[i]]) m[x[i]] = y[i];
        }
    }
    for(auto& [key,value] : m){
        ans += value;
    }
    cout << ans;
    return 0;
}