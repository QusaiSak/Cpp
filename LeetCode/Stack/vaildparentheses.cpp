#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c =='(' || c =='{' || c =='['){
                st.push(c);
            }else{
                if(st.empty()) return false;
                else{
                    if(st.top()=='{' && c=='}'){
                        st.pop();
                    }else if(st.top()=='(' && c==')'){
                        st.pop();
                    }else if(st.top()=='[' && c==']'){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};