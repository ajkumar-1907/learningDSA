#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> rev(queue<int> q) {
    stack<int> s;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    queue<int> reversed = rev(q);

    cout << "Reversed Queue: ";
    while (!reversed.empty()) {
        cout << reversed.front() << " ";
        reversed.pop();
    }
    cout << endl;

    return 0;
}
