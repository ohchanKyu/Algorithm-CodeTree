#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;


int main() {

    int N;
    cin >> N;
    // 도착시간, 머무르는 시간, 인덱스
    vector<tuple<int,int,int>> people(N);

    for(int i=0;i<N;i++){
        int a,t;
        cin >> a >> t;
        people[i] = {a,t,i};
    }
    // 도착시간이 작은것대로 정렬
    sort(people.begin(), people.end());
    // 현재 시간
    int currentTime = 0;
    // 현재 인덱스
    int idx = 0;
    // 정답
    int ans = 0;

    // 번호와 현재 idx
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    while(idx < N || !pq.empty()){

        while(idx < N && get<0>(people[idx]) <= currentTime){
            pq.push({get<2>(people[idx]),idx});
            idx +=1;
        }
        if(!pq.empty()){
            auto [id,i] = pq.top();
            pq.pop();
            int arrive = get<0>(people[i]);
            int time = get<1>(people[i]);
            ans = max(ans,currentTime - arrive);
            currentTime += time;
        }else{
            currentTime = get<0>(people[idx]);
        }
    }
    cout << ans;
    return 0;
}
