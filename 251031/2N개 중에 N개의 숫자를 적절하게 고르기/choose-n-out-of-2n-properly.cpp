#include <bits/stdc++.h>

using namespace std;

int n;
int num[20];
int sum;
int ret = 987654321;

void go(int idx, int start, int val){
    
    if (idx == n){
        int tmp = sum - val;
        ret = min(ret, abs(tmp - val));
        return;
    }
    for(int i=start;i<2*n;i++){
        go(idx+1, i+1, val + num[i]);
    }
}
int main() {

    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    go(0,0,0);
    cout << ret;
    return 0;
}
