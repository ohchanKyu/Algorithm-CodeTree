#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int N, K;
int a[100000], b[100000];
int arr[100001];

int main() {
    
    cin >> N >> K;
    
    vector<unordered_set<int>> v;
    v.resize(N+1);

    for(int i=1;i<=N;i++){
        arr[i] = i;
        unordered_set<int> new_set;
        v[i] = new_set;
        v[i].insert(i);
    }
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i];
    }
    for(int t=0;t<3;t++){
        for(int i=0;i<K;i++){
            int num1 = arr[a[i]]; 
            int num2 = arr[b[i]];
            arr[a[i]] = num2;
            arr[b[i]] = num1;
            v[num2].insert(a[i]);
            v[num1].insert(b[i]);
        }
    }
    for(int i=1;i<=N;i++){
        cout << v[i].size() << "\n";
    }
    return 0;
}
