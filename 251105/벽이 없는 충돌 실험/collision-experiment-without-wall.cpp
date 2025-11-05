#include <bits/stdc++.h>
#define y1 nahc

using namespace std;

int T;
int N,x,y,w;
char d;

// 위 오른 아래 왼
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

struct Element{
    
    int id,x,y,w,d;
    bool isDie = false;

    void die(){
        isDie = true;
    }
};

vector<Element> elements;

int convDir(char c){
    if (c == 'U') return 0;
    else if (c == 'R') return 1;
    else if (c == 'D') return 2;
    else return 3;
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

void move(){
    
    map<pair<int,int>, vector<pair<int,int>>> mp;

    int live = 0;

    for(Element &e : elements){

        if (e.isDie) continue;

        int d = e.d;
        int w = e.w;
        int id = e.id;
        e.x = e.x + dx[d];
        e.y = e.y + dy[d];
        mp[{e.x,e.y}].push_back({w,id});
        live++;
    }

    if (mp.size() == live) return;

    for(auto it : mp){
        if (it.second.size() == 1) continue;
        sort(it.second.begin(),it.second.end(),cmp);
        for(int i=1;i<it.second.size();i++){
            int id = it.second[i].second;
            elements[id].die();
        }
    }
}
bool check(){
    
    for(int i=1;i<=N;i++){
        if (elements[i].isDie) continue;
        for(int j=1;j<=N;j++){    
            if (elements[j].isDie || i == j) continue;
            int d1 = elements[i].d;
            int d2 = elements[j].d;

            int x1 = elements[i].x;
            int y1 = elements[i].y;

            int x2 = elements[j].x;
            int y2 = elements[j].y;
            if ((d1 + 2) % 4 == d2){
                // 오른 왼
                if (d1 & 1){
                    if(d1 < d2 && x1 < x2) return true;
                }
                // 위 아래
                else{
                    if (d1 < d2 && y1 < y2) return true;
                }
            }
            if ((d1 + 1) % 4 == d2){
                int bx,by;
                int tx,ty;
                if (d1 & 1){
                    bx = x2;
                    by = y1;
                    tx = x1;
                    ty = y2;
                }else{
                    bx = x1;
                    by = y2;
                    tx = x2;
                    ty = y1;
                }
                if (abs(bx-tx) == abs(by - ty)) return true;
            }
        }
    }
    return false;
}
int main() {

    cin >> T;
    while(T--){
        cin >> N;
        elements.resize(N+1);
        int ret = 0;

        for(int i=1;i<=N;i++){
            cin >> x >> y >> w >> d;
            int dir = convDir(d);
            elements[i] = {i, x * 2,  y * 2, w, dir};
        }
        while(true){
            if (check()){
                move();
                ret++;
            }else break;
        }
        if (ret == 0) cout << -1 << "\n";
        else cout << ret << "\n";
        elements.clear();

    }


    return 0;
}