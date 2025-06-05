#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int n;
string words[10000];

int main() {
    
    cin >> n;
    map<string,int> m;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        m[words[i]] += 1;
    }
    for(auto& [key,value] : m){
        cout << key << " " << fixed << setprecision(4) << static_cast<double>(value) / n * 100 << "\n";
    }

    return 0;
}
