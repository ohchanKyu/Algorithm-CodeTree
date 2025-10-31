#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int main() {

    cin >> n;
    for(int i=n;i>=1;i--){
        v.push_back(i);
    }

    do{
        for(int a : v){
            cout << a << " ";
        }
        cout << "\n";
    }while(prev_permutation(v.begin(),v.end()));

    return 0;
}
