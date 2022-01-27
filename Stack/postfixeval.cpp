/*write a C++ program to evaluate value of a postfix expression 
Test case:
i/p:Enter Postfix Expression
231*+9-
o/p: -4
*/
#include <bits/stdc++.h>

#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Epf {
public:
    stack<int> st;
    bool isop(char c) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            return true;
        } else {
            return false;
        }
    }
    int eval(string c) {
        for (int i = 0; i < c.length(); i++) {
            if (isop(c[i])) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                switch (c[i]) {
                    case '+':
                        st.push(b + a);
                        break;
                    case '-':
                        st.push(b - a);
                        break;
                    case '*':
                        st.push(b * a);
                        break;
                    case '/':
                        st.push(b / a);
                        break;
                }
            } else {
                st.push(c[i] - '0');
            }
        }
        return st.top();
    }
};
int main() {
    Epf epe;
    string exp;
    cout << "Enter Postfix expression" << endl;
    cin >> exp;
    cout << epe.eval(exp);
    return 0;
}