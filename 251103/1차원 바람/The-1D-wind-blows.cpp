#include <bits/stdc++.h>

using namespace std;

int n, m, q, x;
vector<vector<int>> grid;

void shift(int row,int d){
    if (d){
        rotate(grid[row].begin(), grid[row].begin() + 1, grid[row].end());
    }else{
        rotate(grid[row].rbegin(),grid[row].rbegin() + 1, grid[row].rend());
    }
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
bool check(int row1,int row2){
    for(int i=0;i<m;i++){
        if (grid[row1][i] == grid[row2][i]) return true;
    }
    return false;
}

void go(int row, int d){

    shift(row,d);
    int drow = row - 1;
    int urow = row + 1;
    int sd = d;

    while(drow >= 0){
        if (!check(drow+1, drow)) break;
        d ^= 1;
        shift(drow,d);
        drow--;
    }
    d = sd;
    while(urow < n){
        if (!check(urow-1,urow)) break;
        d ^= 1;
        shift(urow,d);
        urow++;
    }
}
int main() {

    cin >> n >> m >> q;

    grid.resize(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;
        int dd = (d == 'L') ? 0 : 1;
        go(r - 1, dd);
    }
    print();

    return 0;
}
