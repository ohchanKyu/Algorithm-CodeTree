#include <iostream>
#include <map>

using namespace std;

int n;
int arr[100000];

int main() {

    cin >> n;

    map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (m.find(arr[i]) == m.end()) m[arr[i]] = i + 1;

    }
    for(auto& [key,value] : m){
        cout << key << " " << value << "\n";
    }
    return 0;
}
