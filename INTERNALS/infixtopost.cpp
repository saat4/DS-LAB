// convert infix to postfix using stack
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isop(char c) {
        if (c == '+' || c == '-' || c == '*' || c == '/') return true;
        return false;
    }
    int prec(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }
    string infixtopostfix(string s) {
        stack<char> st;
        string ans;
        for (int i = 0; i < s.length(); i++) {
            if (isop(s[i])) {
                while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            } else if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                while (st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            } else {
                ans += s[i];
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
int main() {
    string s;
    Solution sol;
    cout << "Enter infix expression : ";
    cin >> s;
    cout << "Postfix expression : " << sol.infixtopostfix(s) << endl;
}

// Enter infix expression : a + b* c / d - e
// Postfix expression : abc* d / +e -