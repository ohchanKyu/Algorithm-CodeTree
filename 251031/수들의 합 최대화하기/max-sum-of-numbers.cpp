#include <bits/stdc++.h>

using namespace std;

int n;
int grid[10][10];
int ret;
vector<int> row;
vector<int> col;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        row.push_back(i);
        col.push_back(i);
    }
    
    do{
        int cnt = 0;
        int tmp = 0;
        for(int r : row){
            tmp += grid[r][cnt++];
        }
        ret = max(ret,tmp);
    }while(next_permutation(row.begin(),row.end()));
    cout << ret;

    return 0;
}
