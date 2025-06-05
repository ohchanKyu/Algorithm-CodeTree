#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
string words[1000];

int main() {
    
    cin >> n;

    unordered_map<string,int> m;
    int maxV = 0;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        sort(words[i].begin(),words[i].end());
        m[words[i]] += 1;
        maxV = max(maxV,m[words[i]]);
    }
    cout << maxV;

    return 0;
}
