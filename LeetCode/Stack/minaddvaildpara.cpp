#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<int> is_ok(s.length(),0);
        stack<int> st;
        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(!st.empty()){
                    is_ok[st.top()] = 1;
                    is_ok[i] = 1;
                    st.pop();
                }else{
                    continue;
                }
            }else continue;
        }
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] =='(' || s[i] == ')'){
                if(is_ok[i] == 0) ans++;
                else continue;
            }
        }
        return ans;
    }
};
