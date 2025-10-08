#include <bits/stdc++.h>

using namespace std;

int N;
int A[1004];
int len;
int lis[1004];

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
        auto pos = lower_bound(lis,lis+len,A[i]);
        if (*pos == 0){
            len++;
        }
        *pos = A[i];
    }
    cout << len;

    return 0;
}