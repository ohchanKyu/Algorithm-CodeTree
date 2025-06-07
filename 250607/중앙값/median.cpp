#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t;
int m;

int main() {

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m;
        priority_queue<int> maxHeap; // Left 중간값보다 작거나 같은값 ( 내림차순 )
        priority_queue<int,vector<int>,greater<int>> minHeap; // Right 중간값보다 큰 값 ( 오름차순 )
        vector<int> ans;

        for (int j = 0; j < m; j++) {
            
            int x;
            cin >> x;
            
            if (maxHeap.empty() || x <= maxHeap.top()){
                maxHeap.push(x);
            }else{
                minHeap.push(x);
            }
            
            if (maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else if (minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            if ((j+1) % 2 == 1) ans.push_back(maxHeap.top());
        }
        for(int n : ans){
            cout << n << " ";
        }
        cout << "\n";
    }
    return 0;
}
