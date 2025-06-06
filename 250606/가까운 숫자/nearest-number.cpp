#include <iostream>
#include <set>
#include <limits.h>

using namespace std;

int n;
int queries[100000];
long minV = LONG_MAX;

int main() {
    
    cin >> n;
    set<int> s;
    s.insert(0);

    set<int>::iterator it;
    
    for (int i = 0; i < n; i++) {

        cin >> queries[i];
        s.insert(queries[i]);
        it = s.lower_bound(queries[i]);
        it--;
        long target1 = long(queries[i] - *it);
        it++;
        it++;
        if (it == s.end()){
            minV = min(minV,target1);
        }else{
            long target2 = long(*it - queries[i]);
            minV = min(minV,min(target1,target2));
        }
        cout << minV << "\n";
    }
    return 0;
}
