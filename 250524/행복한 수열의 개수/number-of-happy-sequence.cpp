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

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        bool found = false;
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == grid[i][j - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt >= m) {
                found = true;
            }
        }
        if (n == 1 && m == 1) found = true;
        if (found) ans++;
    }

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        bool found = false;
        for (int j = 1; j < n; j++) {
            if (grid[j][i] == grid[j - 1][i]) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt >= m) {
                found = true;
            }
        }
        if (n == 1 && m == 1) found = true;
        if (found) ans++;
    }

    cout << ans;
    return 0;
}
