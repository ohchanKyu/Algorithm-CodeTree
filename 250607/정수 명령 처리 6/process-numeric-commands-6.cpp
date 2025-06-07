#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
string command;

int main() {

    cin >> N;
    priority_queue<int> q;

    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push") {
            int x;
            cin >> x;
            q.push(x);
        }else if (command == "pop"){
            cout << q.top() << "\n";
            q.pop();
        }else if (command == "size"){
            cout << q.size() << "\n";
        }else if (command == "empty"){
            if (q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else{
            cout << q.top() << "\n";
        }
    }

    return 0;
}
