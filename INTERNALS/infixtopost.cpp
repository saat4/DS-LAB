#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    stack<char> st;
    string res;
    int prec(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }
    bool isop(char c) {
        if (c == '+' || c == '-' || c == '*' || c == '/') return true;
        return false;
    }
    string infixToPostfix(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (isop(s[i])) {
                while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            } else {
                res += s[i];
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
int main() {
    Solution sol;
    string exp;
    cout << "Enter expression" << endl;
    cin >> exp;
    cout << "Postfix form: " << sol.infixToPostfix(exp) << endl;
    return 0;
}
/*
Write C++ program to convert infix expression to postfix
Sample Test case:
Enter expression
input=a+b*c/d-e
output :
Postfix form: abc*d/+e-
*/