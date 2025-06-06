#include <iostream>
#include <set>
#include <queue>

using namespace std;

int N, G;

typedef pair<int,set<int>> groupSet;
struct Compare{

    bool operator()(const groupSet &a,const groupSet &b){
        return a.first > b.first;
    }
};


int main() {

    cin >> N >> G;
    priority_queue<groupSet, vector<groupSet>, Compare> q;
    set<int> invited;

    for (int i = 0; i < G; i++) {
        int groupSize;
        cin >> groupSize;
        set<int> groups;
        groupSet groupComponent = groupSet(groupSize, groups);

        for (int j = 0; j < groupSize; j++) {
            int groupMember;
            cin >> groupMember;
            if (j == 0) invited.insert(groupMember);
            groupComponent.second.insert(groupMember);
        }
        q.push(groupComponent);
    }

    for(int i=0;i<G;i++){
        groupSet groupComponent = q.top();
        q.pop();
        set<int> groups = groupComponent.second;
        int groupSize = groupComponent.first;
        
        int cnt = 0;
        for(int g : groups){
            if (invited.find(g) != invited.end()) cnt += 1;
        }
        if (cnt == groupSize - 1){
            for(int g : groups){
                if (invited.find(g) == invited.end()) invited.insert(g);
            }
        }
    }
    cout << invited.size();
    return 0;
}
