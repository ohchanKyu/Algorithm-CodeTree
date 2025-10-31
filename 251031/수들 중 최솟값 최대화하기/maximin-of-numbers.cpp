#include <bits/stdc++.h>

using namespace std;

int n;
int grid[10][10];
vector<int> row;
int ret;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
        row.push_back(i);
    }
    do{
        int cnt = 0;
        int minV = 10004;
        for(int r : row){
            minV = min(minV,grid[r][cnt++]);
        }
        ret = max(ret,minV);

    }while(next_permutation(row.begin(),row.end()));
    cout << ret;
    
    return 0;
}
