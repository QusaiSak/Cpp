#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixtopostfix(string infix) {
    stack<char> s; 
    string postfix; 

    for (char c : infix) {                                                               
        if (isalnum(c)) { 
            postfix += c;
        } else if (c == '(') { 
            s.push(c);
        } else if (c == ')') { 
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop(); 
            }
        } else { 
            while (!s.empty() && precedence(c) <= precedence(s.top()) && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix = "2345678";
    string postfix = infixtopostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
