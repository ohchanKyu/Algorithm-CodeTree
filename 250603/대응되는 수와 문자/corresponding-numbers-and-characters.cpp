#include <iostream>
#include <string>
#include <unordered_map>
#include <typeinfo>

using namespace std;

int n, m;
string words[100000];
string queries[100000];

int main() {

    
    unordered_map<string,int> stringMap;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
        stringMap[words[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
        if (stringMap[queries[i]] == 0) cout << words[stoi(queries[i])] << "\n";
        else cout << stringMap[queries[i]] << "\n";
    }

    return 0;
}
