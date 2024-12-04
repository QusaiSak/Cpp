#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string newnum;
        for (char c : num) {
            while (!newnum.empty() && k > 0 && newnum.back() > c) {
                newnum.pop_back();
                k--;
            }
            newnum.push_back(c);
        }
        while(k>0){
            newnum.pop_back();
            k--;
        }
        int i = 0;
        while(i<newnum.length() && newnum[i] == '0'){
            i++;
        }
        if(i == newnum.length()) return "0";
        return newnum.substr(i);
    }
};