#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxsumsubarray(vector<int>arr , int k){
            int max_value = INT_MIN;
            int curr_sum = 0;
            for(int i = 0; i < arr.size(); i++){
                curr_sum+=arr[i];
                if(i >= k-1){
                    max_value = max(max_value, curr_sum);
                    curr_sum-=arr[i-k+1];
                }
            }
            return max_value;
        }
};

int main() {
    Solution s;
    vector<int> arr = {4,3,1,7,8,1,2,8,1,0};
    int k = 3;
    cout << "Maximum sum of a subarray of size " << k << " is: " << s.maxsumsubarray(arr, k) << endl;
    return 0;
}