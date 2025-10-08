#include <bits/stdc++.h>

using namespace std;

int N,x;
vector<int> A;
int incre[1004];
int decre[1004];
int len;
int lis[1004];
int ret;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x;
        A.push_back(x);
    }
    for(int i=0;i<N;i++){
        auto pos = lower_bound(lis,lis+len,A[i]);
        if (*pos == 0){
            len++;
        }
        *pos = A[i];
        incre[i] = len;
    }
    len = 0;
    memset(lis,0,sizeof(lis));
    reverse(A.begin(),A.end());
    for(int i=0;i<N;i++){
        auto pos = lower_bound(lis,lis+len,A[i]);
        if (*pos == 0){
            len++;
        }
        *pos = A[i];
        decre[N-i-1] = len;
    }

    for(int i=0;i<N;i++){
        ret = max(ret,incre[i] + decre[i] - 1);
    }
    cout << ret;
    
    return 0;
}