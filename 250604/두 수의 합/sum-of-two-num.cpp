#include <iostream>
#include <vector>

using namespace std;

int n, k;
int arr[100000];
long long ans = 0;

void dfs(int depth,int start,vector<int> nums);

int main() {

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> nums;
    dfs(0,0,nums);
    cout << ans; 
    return 0;
}

void dfs(int depth,int start,vector<int> nums){

    if (depth == 2){
        long long sumV = 0;
        for(int num : nums){
            sumV += num;
        }
        if (sumV == k) ans += 1;
        return;
    }

    for(int i=start;i<n;i++){
        nums.push_back(arr[i]);
        dfs(depth+1,i,nums);
        nums.pop_back();
    }
}
