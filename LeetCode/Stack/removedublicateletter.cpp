#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
       vector<int> freq(26,0);
       for(int i = 0 ; i<s.length();i++) freq[s[i]-'a']=i;

       stack<char> st;
       vector<bool> seen(26,false);
       for(int i = 0 ; i<s.length();i++){
            int curr = s[i]-'a';
            if(seen[curr]){
                continue;
            }
            while(!st.empty() && st.top() > s[i] && i<freq[st.top()-'a']){
                seen[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[curr] = true;
        }
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};