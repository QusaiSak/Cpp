class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num:nums) set.insert(num);
        int longseries = 0;
        for(int num : nums){
            if(set.find(num-1) == set.end()){
                int currrnum = num;
                int currseries = 1;
                while(set.find(currnum+1) != set.end()){
                    currnum ++;
                    currseries++;
                }
                longseries = max(longseries, currseries);
            }
        }
        return longseries;
    }
};