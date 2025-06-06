#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int N, G;


int main() {

    cin >> N >> G;
   
    vector<unordered_set<int>> groups(G);
    vector<bool> isFixed(G,false);

    // member N 별로 속한 group 목록
    vector<vector<int>> memberToGroup(N+1);
    unordered_set<int> invited;
    vector<int> groupMemberCount(G,0);

    for (int i = 0; i < G; i++) {
        int groupSize;
        cin >> groupSize;
        for (int j = 0; j < groupSize; j++) {
            int groupMember;
            cin >> groupMember;
            groups[i].insert(groupMember);
            memberToGroup[groupMember].push_back(i);
        }
    }
    queue<int> q;
    // member id
    q.push(1);
    invited.insert(1);
    
    while(!q.empty()){

        int memberId = q.front(); q.pop();
        
        for(int groupId : memberToGroup[memberId]){
            if (isFixed[groupId]) continue;
            groupMemberCount[groupId] += 1;
            if (groupMemberCount[groupId] == groups[groupId].size() - 1){
                isFixed[groupId] = true;
                for(int member : groups[groupId]){
                    if (invited.find(member) == invited.end()){
                        invited.insert(member);
                        q.push(member);
                    }
                }
            }
        }
    }
    cout << invited.size();
    return 0;
}
