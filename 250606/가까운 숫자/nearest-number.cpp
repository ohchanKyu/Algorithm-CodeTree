#include <iostream>
#include <set>
#include <limits.h>

using namespace std;

int n;
int queries[100000];

int main() {
    
    cin >> n;
    set<int> s;
    s.insert(0);

    set<int>::iterator it;
    
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
        s.insert(queries[i]);

        long minV = LONG_MAX;

        for(int x : s){
            it = s.upper_bound(x);
            if (it == s.end()) continue;
            int upper = *it;
            it--;
            if (it == s.end()) continue;
            int down = *it;
            minV = min(minV,(long)(upper-down));
        }
        cout << minV << "\n";
    }
    return 0;
}
