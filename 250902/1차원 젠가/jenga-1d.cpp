#include <bits/stdc++.h>

using namespace std;

int n;
int s1, e1;
int s2, e2;
vector<int> blocks;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        blocks.push_back(x);
    }
    // s1 -> e1 까지 뺌
    cin >> s1 >> e1;
    s1--;
    blocks.erase(blocks.begin() + s1, blocks.begin() + e1);
    cin >> s2 >> e2;
    s2--;
    blocks.erase(blocks.begin() + s2, blocks.begin() + e2);

    cout << blocks.size() << "\n";
    for(int a : blocks){
        cout << a << "\n";
    }

    return 0;
}
