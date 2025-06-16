#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> coord;
int n;
int grid[20][20];
int tempGrid[20][20];
vector<coord> boom;

int dx[3][4] = {{ 2,-2,1,-1 },{ 1,-1,0,0},{1,-1,1,-1}};
int dy[3][4] = {{0,0,0,0},{0,0,1,-1},{1,1,-1,-1}};
int maxV = 0;

void calculateBoom(vector<int> types);
void clear();
void dfs(int index,vector<int> types);

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            tempGrid[i][j] = grid[i][j];
            if (grid[i][j] == 1) boom.push_back(coord(i,j));
        }
    }
    vector<int> types;
    dfs(0,types);
    cout << maxV;
    return 0;
}
void dfs(int index,vector<int> types){

    if (index == boom.size()){
        calculateBoom(types);
        clear();
        return;
    }
    for(int i=0;i<=2;i++){
        types.push_back(i);
        dfs(index+1, types);
        types.pop_back();
    }
}
void clear(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tempGrid[i][j] = grid[i][j];
        }
    }
}
void calculateBoom(vector<int> types){
    
    for(int i=0;i<boom.size();i++){
        
        coord target = boom[i];
        int x = target.first;
        int y = target.second;

        int type = types[i];
        for(int d=0;d<4;d++){
            int nx = x + dx[type][d];
            int ny = y + dy[type][d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            tempGrid[nx][ny] = 1;
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (tempGrid[i][j] == 1) cnt += 1;
        }
    }
    maxV = max(maxV,cnt);
}