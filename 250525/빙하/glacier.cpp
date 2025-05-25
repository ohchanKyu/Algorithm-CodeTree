#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> coord;
int N, M;
int a[200][200];
int tempA[200][200];

vector<coord> tempGlance;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void meltGlance(coord target);
void check1();
void rollback();

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    int time = 0;
    int lastLeft = 0;
    while (true) {

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i][j] == 1) cnt += 1;
            }
        }
        if (cnt == 0) break;
        check1();
        queue<coord> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i][j] == 1) {
                    q.push(coord(i, j));
                }
                tempA[i][j] = a[i][j];
            }
        }
        lastLeft = q.size();
        for (int i = 0; i < lastLeft; i++) {
            coord target = q.front();
            q.pop();
            meltGlance(target);
        }

        rollback();
        time += 1;
    }
    cout << time << " " << lastLeft;
    return 0;
}
void meltGlance(coord target) {

    int x = target.first;
    int y = target.second;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (tempA[nx][ny] == 0) {
            a[x][y] = 0;
            return;
        }
    }
}

void check1() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) {
                bool isSurround = true;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                        isSurround = false;
                        break;
                    }
                    else if (a[nx][ny] == 0) {
                        isSurround = false;
                        break;
                    }
                }
                if (isSurround) {
                    a[i][j] = 2;
                    tempGlance.push_back(coord(i, j));
                }

            }
        }
    }
}

void rollback() {

    for (coord c : tempGlance) {
        a[c.first][c.second] = 0;
    }
    tempGlance.clear();
}
