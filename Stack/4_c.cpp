/*
Check for Balanced Brackets using Stack
Given a string, check if it is a valid parentheses string.

Sample Test Cases : 
Input : 
Enter expression
{{[[(())]]}}
Output:
Braces are balanced

Input:
Enter expression
{[(])}
Output:
Braces are imbalanced
*/

#include <iostream>
#include <stack>
using namespace std;

class BracesBalance {
public:
    bool areBalancedBraces(string str) {
        stack<char> s;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
                s.push(str[i]);
            } else if (str[i] == '}' || str[i] == ']' || str[i] == ')') {
                if (s.empty()) {
                    return false;
                }
                char c = s.top();
                if (str[i] == '}' && c != '{') {
                    return false;
                } else if (str[i] == ']' && c != '[') {
                    return false;
                } else if (str[i] == ')' && c != '(') {
                    return false;
                }
                s.pop();
            }
        }
        if (s.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    BracesBalance bb;
    string expr;
    cout << "Enter expression" << endl;
    cin >> expr;
    if (bb.areBalancedBraces(expr))
        cout << "Braces are balanced";
    else
        cout << "Braces are imbalanced";
    return 0;
}

// Enter expression
// {{[[(())]]}}
// Braces are balanced