#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        int res = 0;
        char sign = '+';
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char curr = s[i];
            
            if (isdigit(curr)) {
                num = num * 10 + (curr - '0');
            }
            
            if ((!isdigit(curr) && !isspace(curr)) || i == n - 1) {
                if (sign == '+') {
                    st.push(num);
                } else if (sign == '-') {
                    st.push(-num);
                } else if (sign == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if (sign == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                sign = curr;
                num = 0;  
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};