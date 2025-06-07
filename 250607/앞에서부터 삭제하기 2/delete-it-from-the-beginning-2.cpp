#include <iostream>
#include <limits.h>
#include <set>
#include <iomanip>

using namespace std;

int N;
int arr[100000];
long sum[100000];
bool isRemove[100000];
double maxV = 0;

int main() {
    
    cin >> N;
    set<pair<int,int>> s;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        s.insert(make_pair(arr[i],i));
    }

    sum[0] = arr[0];
    for(int i=1;i<N;i++){
        sum[i] = sum[i-1] + arr[i];
    }
    int start = 0;
    // N
    while(start < N-2){
        isRemove[start] = true;
        auto it = s.begin();
        int targetIndex;
        for(;it != s.end();it++){
            if (isRemove[(*it).second]) continue;
            targetIndex = (*it).second;
            break;
        }
        maxV = max(maxV, double(sum[N-1] - sum[start] - arr[targetIndex]) / (N-start-2));
        start += 1;
    }
    cout << fixed << setprecision(2) << maxV;
    return 0;
}
