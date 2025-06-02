#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];

int main() {

    cin >> n;
    unordered_map<int,int> m;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        cin >> k[i];
        if (cmd[i] == "add") {
            cin >> v[i];
            m[k[i]] = v[i];
        }else if (cmd[i] == "remove"){
            m[k[i]] = 0;
        }else{
            if (m[k[i]] != 0) cout << m[k[i]] << "\n";
            else cout << "None" << "\n";
        }
    }


    return 0;
}
