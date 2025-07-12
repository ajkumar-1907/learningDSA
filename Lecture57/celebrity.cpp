#include<bits/stdc++.h>
using namespace std;

class Solution 
{
private:
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        return M[a][b] == 1;
    }

public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        for(int i = 0; i < n; i++) {
            s.push(i);
        }

        while(s.size() > 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if(knows(M, a, b, n)) {
                s.push(b);
            } else {
                s.push(a);
            }
        }

        int candidate = s.top();

        for(int i = 0; i < n; i++) {
            if(i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
                return -1;
            }
        }

        return candidate;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
    return 0;
}
