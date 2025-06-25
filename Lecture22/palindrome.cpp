#include <iostream>
#include <string>
#include <cctype>

using namespace std;

inline bool valid(char ch) {
    return std::isalnum(static_cast<unsigned char>(ch));
}

inline char toLowerCase(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}


bool isPalindrome(const string& s) {
    string tmp;
    tmp.reserve(s.size());   

    for (char ch : s)
        if (valid(ch))
            tmp.push_back(toLowerCase(ch));

    size_t i = 0, j = tmp.size();
    if (j == 0) return true;            
    --j;                              

    while (i < j) {
        if (tmp[i] != tmp[j]) return false;
        ++i;  
        --j;
    }
    return true;
}

int main() {
    std::string line;
    std::getline(cin, line); 

    cout << (isPalindrome(line) ? "true" : "false") << '\n';
    return 0;
}
