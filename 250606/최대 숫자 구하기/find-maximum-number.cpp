#include <iostream>
#include <set>

using namespace std;

int n, m;
int queries[100000];

int main() {
    
    cin >> n >> m;
    set<int> set;

    for(int i=1;i<=m;i++){
        set.insert(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
        set.erase(queries[i]);
        cout << *set.rbegin()  << "\n";
    }


    return 0;
}
