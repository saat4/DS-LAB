/* Write C++ program to convert infix expression to postfix

Sample Test case:

Enter expression                                                                                                        
input=a+b*c/d-e
output=                                                                                                      
Postfix form: abc*d/+e-   

*/
#include <iostream>
#include <stack>
using namespace std;
class ITFConversion {
public:
    stack<char> st;
    string res;
    int prec(char c) {
        //Write code here
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }
    bool isop(char c) {
        if (c == '+' || c == '-' || c == '*' || c == '/') return true;
        return false;
    }
    string infixToPostfix(string s) {
        //Write code here
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
    ITFConversion itf;
    string exp;
    cout << "Enter expression" << endl;
    cin >> exp;
    cout << "Postfix form: " << itf.infixToPostfix(exp) << endl;
    return 0;
}