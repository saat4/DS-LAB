// Check string palindrome using stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkpal(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            st.push(s[i]);
        }
        for (int i = 0; i < s.length(); i++) {
            if (st.top() != s[i]) {
                return false;
            }
            st.pop();
        }
        return true;
    }
};
int main() {
    Solution s;
    string str;
    cout << "Enter a string : ";
    cin >> str;
    int r = s.checkpal(str);
    if (r == 1) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not palindrome" << endl;
    }
}

// Enter a string : racecar
// Palindrome
// Enter a string : hello
// Not palindrome