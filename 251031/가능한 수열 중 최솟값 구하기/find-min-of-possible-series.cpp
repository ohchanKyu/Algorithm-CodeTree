#include <bits/stdc++.h>

using namespace std;

int n;
map<string,int> ret;

bool check(string s, int t){

    string tmp = s + to_string(t);
    int lastIdx = tmp.size() - 1;

    for(int _size=1; _size <= tmp.size() / 2;_size++){
        int idx = lastIdx - _size + 1;
        string a = tmp.substr(idx, _size);
        string b = tmp.substr(idx - _size, _size);
        if (a == b) return false;
    }
    return true;
}

void go(int idx, string s){
    
    if (idx == n){
        ret[s] = 1;
        return;
    }
    for(int i=4;i<=6;i++){
        if (!check(s,i)) continue;
        s += to_string(i);
        go(idx+1,s);
        s.pop_back();
    }
}

int main() {
    
    cin >> n;
    go(0,"");
    for(auto it : ret){
        cout << it.first;
        break;
    }
    return 0;
}
