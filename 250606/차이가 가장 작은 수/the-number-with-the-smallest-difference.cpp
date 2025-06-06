#include <iostream>
#include <set>

using namespace std;

int n, m;
int arr[100000];

int main() {

    cin >> n >> m;
    set<int> s;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    int minV = *s.begin();
    bool isSuccess = false;
    auto it = s.begin();
    it++;
    for(;it != s.end();it++){
        int diff = *it - minV;
        if (diff >= m){
            isSuccess = true;
            cout << diff << "\n";
            return 0;
        }
    }
    if (!isSuccess) cout << -1;
    return 0;
}
