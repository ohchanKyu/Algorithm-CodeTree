#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n, m;

int main() {

    // 삭제된 숫자
    set<int> s;
    // 길이, 시작 숫자, 끝 숫자
    set<tuple<int,int,int>> s_len;

    cin >> n >> m;
    s.insert(-1); s.insert(n+1);
    s_len.insert(make_tuple(n+1,-1,n+1));

    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        set<int>::iterator it;
        it = s.upper_bound(y);
        
        int z = *it;
        it --;
        int x = *it;
        
        s.insert(y);
        s_len.erase(make_tuple(z-x-1,x,z));
        s_len.insert(make_tuple(y-x-1,x,y));
        s_len.insert(make_tuple(z-y-1,y,z));
        cout << get<0>(*s_len.rbegin()) << "\n";
    }

    return 0;
}
