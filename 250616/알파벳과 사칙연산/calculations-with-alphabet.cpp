#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <set>

using namespace std;

string expression;
vector<char> op;
vector<char> charlist;

set<char> s;
unordered_map<char,int> m;
bool alpha[6];

int maxV = INT_MIN;
int num = 0;

void dfs(int index, vector<int> v){

    if (index == num){
        for(int i=0;i<v.size();i++){
            m[charlist[i]] = v[i];
        }
        int val = m[expression[0]];
        int cnt = 2;
        for(char c : op){
            if (c == '-'){
                val -= m[expression[cnt]];
            }else if (c == '+'){
                val += m[expression[cnt]];
            }else if (c == '*'){
                val *= m[expression[cnt]];
            }
            cnt += 2;
        }
        maxV = max(maxV,val);
        return;
    }
    for(int i=1;i<=4;i++){
        v.push_back(i);
        dfs(index+1,v);
        v.pop_back();
    }
}

int main() {

    cin >> expression;
    for(int i=0;i<expression.length();i++){
        if(i % 2 == 1) op.push_back(expression[i]);
        else s.insert(expression[i]);
    }
    auto it = s.begin();
    for(;it != s.end();it++){
        charlist.push_back(*it);
    }
    num = s.size();
    vector<int> v;
    dfs(0,v);
    cout << maxV;
    return 0;
}
