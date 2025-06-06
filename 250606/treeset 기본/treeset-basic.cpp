#include <iostream>
#include <set>

using namespace std;

int n;
string command[100000];
int x[100000];

int main() {

    cin >> n;
    set<int> set;

    for (int i = 0; i < n; i++) {
        cin >> command[i];
        if (command[i] == "add" || command[i] == "remove" ||
            command[i] == "find" || command[i] == "lower_bound" ||
            command[i] == "upper_bound") {
            cin >> x[i];
            if (command[i] == "add") {
                set.insert(x[i]);
            }
            else if (command[i] == "remove") {
                set.erase(x[i]);
            }
            else if (command[i] == "find") {
                if (set.find(x[i]) == set.end())
                    cout << "false\n";
                else
                    cout << "true\n";
            }
            else if (command[i] == "lower_bound") {
                auto it = set.lower_bound(x[i]);
                if (it == set.end())
                    cout << "None\n";
                else
                    cout << *it << "\n";
            }
            else if (command[i] == "upper_bound") {
                auto it = set.upper_bound(x[i]);
                if (it == set.end())
                    cout << "None\n";
                else
                    cout << *it << "\n";
            }
        }else{
            if (command[i] == "largest"){
                if (!set.empty()){
                    cout << *set.rbegin() << "\n";
                }else{
                    cout << "None\n";
                }
            }else{
                if (!set.empty()){
                    cout << *set.begin() << "\n";
                }else{
                    cout << "None\n";
                }
            }
        }
    }


    return 0;
}
