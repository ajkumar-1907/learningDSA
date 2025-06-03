#include <iostream>
#include <vector>

using namespace std;


void solve(string digits, string output, int index, vector<string>& ans, string mapping[]) {


    if(index >= digits.length()) {
        ans.push_back(output);
        return;
    }


    int number = digits[index] - '0';   //convert char to int
    string value = mapping[number];     //get corresponding string from mapping



    for(int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);                         // choose
        solve(digits, output, index + 1, ans, mapping);     // explore
        output.pop_back();                                  // un-choose
    }
}


vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length() == 0)
        return ans;

    string output = "";
    int index = 0;

    //mapping from digits to corresponding letters
    string mapping[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    solve(digits, output, index, ans, mapping);
    return ans;
}

int main() {
    string digits;
    cout << "Enter digits (2-9 only): ";
    cin >> digits;

    vector<string> result = letterCombinations(digits);

    cout << "Possible combinations:\n";
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
