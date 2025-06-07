#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int t;
int m;
int arr[100000];
vector<int> v;

int main() {

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> arr[j];
            v.push_back(arr[j]);
            if ((j+1) % 2 == 1){
                sort(v.begin(),v.end());
                int index = (j+1) / 2;
                cout << v[index] << " ";
            }
        }
        cout << "\n";
        v.clear();
    }
    return 0;
}
