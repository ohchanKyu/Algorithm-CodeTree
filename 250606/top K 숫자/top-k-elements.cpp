#include <iostream>
#include <set>

using namespace std;

int n, k;
int arr[100000];

int main() {
    
    cin >> n >> k;
    set<int> s;

    set<int>::reverse_iterator it;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    it = s.rbegin();
    for(int i=0;i<k;i++){
        cout << *it << " ";
        it--;
    }
    return 0;
}
