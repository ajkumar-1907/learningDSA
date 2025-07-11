#include <iostream>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for (int i = 0; i < n; i++)
            top[i] = -1;

        for (int i = 0; i < s; i++)
            next[i] = i + 1;
        next[s - 1] = -1;

        freespot = 0;
    }

    bool push(int x, int m) {
        if (freespot == -1)
            return false;

        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }

    int pop(int m) {
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main() {
    NStack st(3, 10);  // 3 stacks in total size of 10

    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);
    st.push(40, 3);

    cout << "Popped from stack 1: " << st.pop(1) << endl;
    cout << "Popped from stack 2: " << st.pop(2) << endl;
    cout << "Popped from stack 3: " << st.pop(3) << endl;
    cout << "Popped from stack 1: " << st.pop(1) << endl;
    cout << "Popped from stack 1: " << st.pop(1) << endl; // Underflow

    return 0;
}
