#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int main() {
    cin >> n;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    do{
        for(int a : v){
            cout << a << " ";
        }
        cout << "\n";
    }while(next_permutation(v.begin(),v.end()));

    

    return 0;
}
