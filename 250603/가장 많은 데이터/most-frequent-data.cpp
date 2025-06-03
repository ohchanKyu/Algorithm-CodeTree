#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string words[100000];

int main() {

    unordered_map<string,int> m;

    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        m[words[i]] += 1;
        ans = max(ans,m[words[i]]);
    }
    cout << ans;
    return 0;
}
