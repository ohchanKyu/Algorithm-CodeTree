#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int N, G;


int main() {

    cin >> N >> G;
   
    vector<unordered_set<int>> groups(G);
    vector<bool> isFixed(G,false);
    unordered_set<int> invited;
    invited.insert(1);

    for (int i = 0; i < G; i++) {
        int groupSize;
        cin >> groupSize;
        for (int j = 0; j < groupSize; j++) {
            int groupMember;
            cin >> groupMember;
            groups[i].insert(groupMember);
        }
    }

    bool isChange = true;
    while(isChange){
        
        isChange = false;
        for(int i=0;i<G;i++){
            if (isFixed[i]) continue;
            int count = 0;
            unordered_set<int> groupComponent = groups[i];
            int target;
            for(int g : groupComponent){
                if (invited.find(g) != invited.end()) count += 1;
                else target = g;
            }
            if (count == groupComponent.size() - 1){
                invited.insert(target);
                isFixed[i] = true;
                isChange = true;
            }
        }    
    }
    cout << invited.size();
    return 0;
}
