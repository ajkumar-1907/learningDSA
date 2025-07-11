#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    solve(s, x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original Stack: ";
    printStack(s);

    s = pushAtBottom(s, 0);

    cout << "After Push at Bottom: ";
    printStack(s);

    return 0;
}
