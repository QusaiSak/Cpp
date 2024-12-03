#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isdigit(c)) {
            int num = 0;
            while (i < s.length() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--; // Step back one character to compensate for the loop's extra increment
            st.push(num);
        } else {
            int n2 = st.top(); st.pop();
            int n1 = st.top(); st.pop();

            int res = 0;
            switch (c) {
                case '+': res = n1 + n2; break;
                case '-': res = n1 - n2; break;
                case '*': res = n1 * n2; break;
                case '/': 
                    if (n2 == 0) {
                        throw runtime_error("Division by zero error");
                    }
                    res = n1 / n2; 
                    break;
            }
            st.push(res);
        }
    }

    return st.top();
}

int main() {
    string postfix = "23/"; 
    int result = calculate(postfix);
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Result: " << result << endl;
    return 0;
}
