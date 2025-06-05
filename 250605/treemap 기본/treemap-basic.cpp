#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];

int main() {
    cin >> n;

    map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        if (cmd[i] == "add") {
            cin >> k[i] >> v[i];
            m[k[i]] = v[i];
        } else if (cmd[i] == "remove"){
            cin >> k[i];
            m.erase(k[i]);
        }else if (cmd[i] == "find"){
            cin >> k[i];
            if (m.find(k[i]) != m.end()) cout << m[k[i]] << "\n";
            else cout << "None" << "\n";
        }else{
            if (m.size() == 0) cout << "None" << "\n";
            else{
                for(auto& [key,value] : m){
                    cout << value << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
