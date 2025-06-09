#include <iostream>
#include <set>

using namespace std;

int N, T;


int main() {
    
    cin >> N >> T;
    set<long long> s;

    while(N--){

        int a,b;
        cin >> a >> b;
        // T초후 최종 위치
        long long target = a + (long long)b * T;
        while(1){
            // target보다 크거나 같은 위치 모두 제거
            // 앞지른 사람은 제거하기 위해
            // 출발점이 앞선 사람의 정보가 먼저 주어져서 가능한 로직
            auto it = s.lower_bound(target);
            if (it == s.end()) break;
            s.erase(it);
        }
        // 해당 target을 그룹으로 등록
        s.emplace(target);
    }
    cout << s.size();
    return 0;
}
