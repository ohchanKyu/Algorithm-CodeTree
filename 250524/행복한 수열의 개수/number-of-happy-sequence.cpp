#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int last = grid[i][0];
        int cnt = 1;
        for(int j=1;j<n;j++){
            if (last == grid[i][j]){
                cnt += 1;
            }
            last = grid[i][j];
            if (cnt >= m){
                ans += 1;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        int last = grid[0][i];
        int cnt = 1;
        for(int j=1;j<n;j++){
            if (last == grid[j][i]){
                cnt += 1;
            }
            last = grid[j][i];
            if (cnt >= m){
                ans += 1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
