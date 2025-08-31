#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    // 1 x M 블록이 K번째 열부터 K + M - 1번째 열까지의 공간을 차지하며 떨어짐
    cin >> n >> m >> k;
    k--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int rows = 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=k;j<=k+m-1;j++){
            if (grid[i][j]){
                flag = true;
                break; 
            }
        }
        if (!flag) rows = i;
        else break;
    }
    for(int j=k;j<=k+m-1;j++){
        grid[rows][j] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
