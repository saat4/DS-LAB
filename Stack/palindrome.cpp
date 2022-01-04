// Check string palindrome using stack
#include <bits/stdc++.h>

#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool stringPalindrome(string s) {
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
    int r = s.stringPalindrome(str);
    if (r == 1) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not palindrome" << endl;
    }
}

// Enter a string : malayalam
// Palindrome