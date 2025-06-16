#include <iostream>

using namespace std;

int n, k;
int coins[10];

int main() {
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    int num = n-1;
    int cnt = 0;

    while(k != 0){
        cnt += k / coins[num];
        k = k % coins[num];
        num -= 1;
    }
    cout << cnt;
    return 0;
}
