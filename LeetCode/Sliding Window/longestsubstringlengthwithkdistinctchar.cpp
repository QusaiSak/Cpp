#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestsubstr(string s,int k){
            unordered_map<char,int> map;
            int start = 0, end=0, maxlen = 0;
            while(end<s.size()){
                map[s[end]]++;
                while(map.size()>k){
                    map[s[start]]--;
                    if(map[s[start]] == 0){
                        map.erase(s[start]);
                    }
                    start++;
                }
                if(map.size() == k){
                    maxlen = max(maxlen,end-start+1);
                }
                end++;
            }
            return maxlen;
        }

};
int main(){
    Solution s;
    cout<<s.longestsubstr("aaahhibc",2);
    return 0;
}