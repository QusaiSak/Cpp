class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
       if(nums.empty()) return 0;
       int index = 1;
       for(int i = 1 ; i < n ; i++){
        if(nums[i-1]!=nums[i]) nums[index++] = nums[i];
       }
       return index;
    }
};