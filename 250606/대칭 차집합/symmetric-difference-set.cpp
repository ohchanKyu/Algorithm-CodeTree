#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
int A[200000];
int B[200000];

int main() {

    cin >> n >> m;
    unordered_set<int> diff;
    unordered_set<int> Aset;
    unordered_set<int> Bset;
    for (int i = 0; i < n; i++){
        cin >> A[i];
        Aset.insert(A[i]);
    }
    for (int i = 0; i < m; i++){
        cin >> B[i];
        Bset.insert(B[i]);
    }
    for(int i=0;i<n;i++){
        if (Bset.find(A[i]) == Bset.end()) diff.insert(A[i]);
    }
    for(int i=0;i<m;i++){
        if (Aset.find(B[i]) == Aset.end()) diff.insert(B[i]);
    }
    cout << diff.size();
    return 0;
}
