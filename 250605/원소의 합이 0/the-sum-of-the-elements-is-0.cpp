#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int A[5000];
int B[5000];
int C[5000];
int D[5000];
long ans = 0;

int main() {

    cin >> n;
    
    unordered_map<int,int> m;
    
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) cin >> C[i];
    for (int i = 0; i < n; i++) cin >> D[i];

    // A+B = -C-D
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int target = A[i] + B[j];
            m[target] += 1;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int target = -(C[i] + D[j]);
            if (m[target] != 0){
                ans += m[target];
            }
        }
    }
    
    cout << ans;

    return 0;
}
