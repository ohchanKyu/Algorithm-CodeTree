#include <iostream>
#include <set>

using namespace std;

int T;
int k;
char command[100000];
int n[100000];

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> k;
        set<int> set;

        for (int i = 0; i < k; i++) {
            cin >> command[i] >> n[i];
            if (command[i] == 'I') set.insert(n[i]);
            else if (command[i] == 'D' && n[i] == 1){
                if (!set.empty()){
                    int maxV = *set.rbegin();
                    set.erase(maxV);
                }
            }else{
                if (!set.empty()){
                    int minV = *set.begin();
                    set.erase(minV);
                }
            }
        }
        if (set.empty()) cout << "EMPTY\n";
        else cout << *set.rbegin() << " " <<  *set.begin() << "\n";
    }

    return 0;
}
