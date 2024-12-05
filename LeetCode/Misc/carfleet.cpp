class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

    int size = position.size(),fleet = 1;
    float F_T = float(target);
    vector<pair<float,float>> vec(size);
    for(int i = 0; i < size; i++)vec[i]={(float)position[i], (float)speed[i]};
    sort(vec.begin(),vec.end(),greater<piar<float,float>>());
    pair<int,int> back = vec[0],top;
    for(int i = 0;i<size;i++){
        top=vec[i];
        if((F_T-back.first)/back.second <(F_T-top.first)/top.second){
            fleet++;
            back=top;
        }
    }
    return fleet;
    }
};