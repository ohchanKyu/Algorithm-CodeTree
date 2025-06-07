#include <iostream>
#include <set>

using namespace std;

int n, m;

int main() {

    set<int> s;

    cin >> n >> m;
    for(int i=0;i<=n;i++) s.insert(i);
    
    for (int i = 0; i < m; i++) {
        cin >> x
        s.erase(x);
        int maxV = 0;
        
        auto it = s.begin();
        int current = *it;
        int currentCnt = 1;

        for(;it != s.end();++it){
            if (*it == current + 1){
                currentCnt += 1;
            }
            else currentCnt = 1;
            maxV = max(maxV,currentCnt);
            current = *it;
        }
        cout << maxV << "\n";
    }

    return 0;
}
