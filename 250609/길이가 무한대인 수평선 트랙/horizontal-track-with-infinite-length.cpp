#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int N, T;
int start[100000];
int speed[100000];


int main() {
    
    cin >> N >> T;


    set<pair<int,int>> s;
    map<int,int> m;
    
    for (int i = 0; i < N; i++) {
        cin >> start[i] >> speed[i];
        m[start[i]]= speed[i];
        s.insert({start[i],speed[i]});
    }

    for(int t=0;t<T;t++){

        auto it = s.begin();
        map<int,int> new_m;
        set<pair<int,int>> new_s;

        for(;it != s.end();it++){
            int current = (*it).first;
            int speed = m[current];
            int next = current + speed;
            new_s.insert(make_pair(next, speed));
        }
        it = new_s.begin();
        // 위치에 맞는 속도 갱신
        for(;it != new_s.end();it++){
            int current = (*it).first;
            int speed = (*it).second;
            if (new_m.find(current) == new_m.end()) new_m[current] = speed;
            else{
                new_m[current] = min(new_m[current],speed);
            }
        }
        m = move(new_m);
        s = move(new_s);
    }
    cout << m.size();
    return 0;
}
