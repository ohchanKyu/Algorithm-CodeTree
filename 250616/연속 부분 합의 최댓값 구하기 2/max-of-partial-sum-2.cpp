#include <iostream>
#include <limits.h>

using namespace std;

int n;
int a[100000];
int s[100000];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s[0] = a[0];
    int maxV = INT_MIN;
    for(int i=1;i<n;i++){
        s[i] = max(0,s[i-1]) + a[i];
        maxV = max(maxV,s[i]);
    }
    cout << maxV;
    return 0;
}
