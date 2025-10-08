#include <bits/stdc++.h>

using namespace std;

int N,x;
vector<int> A;
int len;
int lis[1004];

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
       cin >> x;
       A.push_back(x);
    }
    reverse(A.begin(),A.end());
    for(int i=0;i<N;i++){
        auto it = lower_bound(lis,lis+len,A[i]);
        if(*it == 0){
            len++;
        }
        *it = A[i];
    }
    cout << len;
    return 0;
}