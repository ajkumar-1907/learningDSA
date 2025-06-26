#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& inputStack, int count, int size) {
    // Base case: when we reach the middle element
    if (count == size / 2) {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive call
    solve(inputStack, count + 1, size);

    // Push back remaining elements
    inputStack.push(num);
}

// Function to delete the middle element of the stack
void deleteMiddle(stack<int>& inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
}


void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Driver code
int main() {
    stack<int> s;

    // Pushing elements into the stack
    for (int i = 1; i <= 5; i++) {
        s.push(i);  // Stack: 1 (bottom) -> 2 -> 3 -> 4 -> 5 (top)
    }

    cout << "Original Stack (Top to Bottom): ";
    printStack(s);

    deleteMiddle(s, s.size());

    cout << "After Deleting Middle Element: ";
    printStack(s);

    return 0;
}
