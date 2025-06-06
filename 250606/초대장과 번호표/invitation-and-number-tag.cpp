#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, G;

typedef pair<int,set<int>> groupSet;

int main() {

    cin >> N >> G;
   
    vector<set<int>> groups(G);
    vector<bool> isFixed(G,false);
    set<int> invited;
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
            set<int> groupComponent = groups[i];
            for(int g : groupComponent){
                if (invited.find(g) != invited.end()) count += 1;
            }
            if (count == groupComponent.size() - 1){
                for(int g : groupComponent){
                    if (invited.find(g) == invited.end()) invited.insert(g);
                }
                isFixed[i] = true;
                isChange = true;
            }
        }    
    }
    cout << invited.size();
    return 0;
}
