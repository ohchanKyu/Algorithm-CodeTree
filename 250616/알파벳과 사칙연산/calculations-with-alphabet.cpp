#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

string expression;
vector<char> op;

int maxV = INT_MIN;
int num;

void dfs(int index,vector<int> v){

    if (index == num){
        int val = v[0];
        int cnt = 1;
        for(char c : op){
            if (c == '-'){
                val -= v[cnt];
            }else if (c == '+'){
                val += v[cnt];
            }else if (c == '*'){
                val *= v[cnt];
            }
            cnt += 1;
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
    num = expression.length() / 2 + 1;
    for(int i=0;i<expression.length();i++){
        if(i % 2 == 1) op.push_back(expression[i]);
    }
    vector<int> v;
    dfs(0,v);
    cout << maxV;
    return 0;
}
