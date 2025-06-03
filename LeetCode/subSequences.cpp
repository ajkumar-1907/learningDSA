#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solve(vector<string>& ans, string str, string output, int i) {
    // Base case
    if (i >= str.length()) {
        if (!output.empty())
            ans.push_back(output);
        return;
    }

    solve(ans, str, output, i + 1);


    output.push_back(str[i]);
    solve(ans, str, output, i + 1);
}

//function to return all subsequences of a string
vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    solve(ans, str, output, 0);
    return ans;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    vector<string> result = subsequences(str);

    cout << "\nAll non-empty subsequences:\n";
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
