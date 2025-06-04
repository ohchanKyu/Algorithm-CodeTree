#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
int arr[1000];
long long ans = 0;

int main() {

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int target = k - arr[i] - arr[j];
            if (m[target] != 0){
                ans += m[target];
            }
        }
        m[arr[i]] += 1;
    }
    
    cout << ans;
    return 0;
}
