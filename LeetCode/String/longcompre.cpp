class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(),strs.end());
        string s = strs[0];
        string l = strs[strs.size()-1];
        for(int i = 0 ; i<min(s.size(),l.size());i++){
            if(s[i]!=l[i]) return ans;
            ans+=s[i];
        }
        return ans;
    }
};