#include <bits/stdc++.h>

using namespace std;

string A;
int ret = 30;

int main() {

    cin >> A;
    int _size = A.size();

    for(int i=0;i<_size;i++){
        string tmp = A;
        rotate(tmp.rbegin(),tmp.rbegin()+i,tmp.rend());
        
        string str = "";
        int idx = 0;
        while(idx < (int) tmp.size()){
            char c = tmp[idx];
            int cnt = 1;
            for(int i=idx+1;i<tmp.size();i++){
                if (c == tmp[i]){
                    cnt++;
                }else break;
            }
            str.push_back(c);
            str += to_string(cnt);
            idx += cnt;
        }
        ret = min(ret,(int)str.size());
    }
    cout << ret;

    return 0;
}
