#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k);

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}


queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;

    //Push first k elements into stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    //Enqueue elements from stack back to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    //Move the remaining (n-k) elements to the back of the queue
    int rem = q.size() - k;
    while (rem--) {
        q.push(q.front());
        q.pop();
    }

    return q;
}
