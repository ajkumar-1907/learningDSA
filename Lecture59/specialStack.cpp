#include<stack>
#include<limits.h>

 class SpecialStack {
    std::stack<int> s;
    int mini = INT_MAX;

public:
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                s.push(2 * data - mini);  // Push encoded value
                mini = data;              // Update mini

            } else {
                s.push(data);
            }
        }
    }

    int pop() {
        if (s.empty()) return -1;

        int curr = s.top();
        s.pop();

        if (curr < mini) {
            int original = mini;
            mini = 2 * mini - curr;  // Restore previous mini
            return original;
        } else {
            return curr;
        }
    }

    int top() {
        if (s.empty()) return -1;

        int curr = s.top();
        if (curr < mini) {
            return mini;  // Encoded value, return actual minimum
        } else {
            return curr;
        }
    }

    int getMin() {
        if (s.empty()) return -1;
        return mini;
    }
};

 