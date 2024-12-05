class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double>res(n,-1);
        stack<int> s;
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && cars[s.top][1]>=cars[i][1]){
                s.pop();
            }
            while(!s.empty()){
                double collTime = (double)(cars[s.top()][0] - cars[i][0])/(cars[i][1] - cars[s.top()][1]);
                if(collTime<=res[s.top()] || res[s.top()] == -1){
                    res[i]=collTime;
                    break;
                }
                s.pop();
            }
            s.push(i);
        }
        return res;
    }   
};