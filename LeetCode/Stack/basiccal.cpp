#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        int res = 0;
        int sign = 1;
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }else if(s[i] == '+'){
                res+=sign*num;
                sign = 1;
                num = 0;
            }else if(s[i] == '-'){
                res+=sign*num;
                sign = -1;
                num = 0;
            }else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res=0;
                sign = 1;
                num = 0;
            }else if(s[i] == ')'){
                res+=sign*num;
                num = 0;
                int st_sign = st.top(); st.pop();
                int last_res = st.top(); st.pop();
                res*=st_sign;
                res+=last_res;
            }
        }
        res+=sign*num;
        return res;
    }
};