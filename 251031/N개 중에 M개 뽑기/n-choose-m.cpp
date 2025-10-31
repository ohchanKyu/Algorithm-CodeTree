#include <bits/stdc++.h>

using namespace std;

int N, M;

void combi(int idx,int start,vector<int> &v){

    if (idx == M){
        for(int a : v){
            cout << a << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=start;i<=N;i++){
        v.push_back(i);
        combi(idx+1,i+1,v);
        v.pop_back();
    }
}
int main() {

    cin >> N >> M;
    vector<int> tmp;
    combi(0,1,tmp);


    return 0;
}
