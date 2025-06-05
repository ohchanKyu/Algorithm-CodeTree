#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string str;

int main() {

    cin >> str;
    unordered_map<char,int> m;
    
    for(int i=0;i<str.length();i++){
        m[str[i]] += 1;    
    }
    vector<char> ansList;
    for(int i=0;i<str.length();i++){
        if (m[str[i]] == 1) ansList.push_back(str[i]);   
    }
    if (ansList.size() == 0) cout << "None";
    else cout << ansList[0];
    return 0;
}
