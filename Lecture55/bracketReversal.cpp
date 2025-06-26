#include <iostream>
#include <stack>
#include <string>
using namespace std;

int findMinimumCost(string str) {

    // Odd length strings cannot be balanced
    if (str.length() % 2 == 1) {
        return -1;
    }

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '{') {
            s.push(ch);
        } else {
            // ch is '}'
            if (!s.empty() && s.top() == '{') {
                s.pop();  // valid pair found
            } else {
                s.push(ch);  // invalid, push for future processing
            }
        }
    }

    // Stack now contains unbalanced brackets
    int a = 0, b = 0;
    while (!s.empty()) {
        if (s.top() == '{') {
            b++;
        } else {
            a++;
        }
        s.pop();
    }

    // Each (a+1)/2 + (b+1)/2 gives one reversal per two invalid brackets
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main() {
    string expr1 = "{{{{";
    string expr2 = "{{{{}}";
    string expr3 = "}{{}}{{{";

    cout << "Minimum Cost ({{{{): " << findMinimumCost(expr1) << endl;
    cout << "Minimum Cost ({{{{}}): " << findMinimumCost(expr2) << endl;
    cout << "Minimum Cost (}{{}}{{{): " << findMinimumCost(expr3) << endl;

    return 0;
}
