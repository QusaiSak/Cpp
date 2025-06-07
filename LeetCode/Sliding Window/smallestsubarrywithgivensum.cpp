#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int smallestsubarry(vector<int>arr, int target){
            int curr_sum = 0;
            int minlength = INFINITY;
            int start = 0;
            for(int end = 0; end <arr.size(); end++){
                curr_sum+=arr[end];
                while(curr_sum >=target){
                    minlength = min(minlength,end-start+1);
                    curr_sum-=arr[start];
                    start++;
                }
            }
            return minlength;
        }

};

int main(){
    Solution s;
    vector<int> arr = {1, 4, 45, 6, 0, 19};
    int target = 51;
    cout << s.smallestsubarry(arr, target) << endl;
    return 0;
}