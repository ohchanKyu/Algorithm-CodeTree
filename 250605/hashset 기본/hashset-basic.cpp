#include <iostream>
#include <unordered_set>

using namespace std;

int n;
string command[100000];
int x[100000];

int main() {

    cin >> n;
    unordered_set<int> set;

    for (int i = 0; i < n; i++) {
        cin >> command[i] >> x[i];
        if (command[i] == "find"){
            if (set.find(x[i]) != set.end()){
                cout << "true" << "\n";
            }else{
                cout << "false" << "\n";
            }
        }else if (command[i] == "add"){
            set.insert(x[i]);
        }else{
            set.erase(x[i]);
        }   
    }

    return 0;
}
