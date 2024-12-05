class Solution {
    void skipspace(string &s, int &n,int&pos){
        while(pos<n && s[pos=='_']) pos++;
    }
public:
    bool canChange(string start, string target){
        int n = start.length();
        int first = 0 , second = 0 , limit = -1;
        while(first<n){
            skipspace(start,n,first);
            skipspace(target,n,second);
            if(first==n && second==n) return true;
            if(start[first]!=target[second]) return false;
            if(start[first] == 'L' && (second<=limit || second>first)) return false;
            else if (start[first] == 'R' && first>second) return false;

            limit = second;
            first++;
            second++;
        }

        skipspace(start,n,first);
        skipspace(target,n,second);
        return first==n && second==n;
    }
};