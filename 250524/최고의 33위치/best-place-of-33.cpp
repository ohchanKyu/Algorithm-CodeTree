#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int maxV = 0;
    for(int i=0;i<N-2;i++){
        for(int j=0;j<N-2;j++){
            int coin = 0;
            for(int r=0;r<3;r++){
                for(int c=0;c<3;c++){
                    coin += grid[i+r][j+c];
                }
            }
            maxV = max(coin,maxV);
        }
    }
    cout << maxV;
    return 0;
}
