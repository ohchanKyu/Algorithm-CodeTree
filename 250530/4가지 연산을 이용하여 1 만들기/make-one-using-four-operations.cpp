#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> coord;
bool check[1000001];
int N;

int main() {
    
    cin >> N;
    
    queue<coord> q;
    q.push(coord(N,0));
    check[N] = true;

    while(!q.empty()){
        coord now = q.front();
        q.pop();
        int now_x = now.first;
        int count = now.second;

        if (now_x == 1){
            cout << count;
            break;
        }

        if (now_x % 3 == 0){
            int next_x = now_x /3;
            if (next_x > 0  || !check[next_x]){
                check[next_x] = true;
                q.push(coord(next_x,count+1));
            }   
        }
        if (now_x % 2 == 0){
            int next_x = now_x / 2;
            if (next_x > 0 || !check[next_x]){
                check[next_x] = true;
                q.push(coord(next_x,count+1));
            }
        }
        int next_x = now_x - 1;
        if (next_x >= 1 && !check[next_x]){
            check[next_x] = true;
            q.push(coord(next_x,count+1));
        }
        next_x = now_x + 1;
        if (next_x <= 1000000 && !check[next_x]){
            check[next_x] = true;
            q.push(coord(next_x,count+1));
        }
    }
    
    return 0;
}
