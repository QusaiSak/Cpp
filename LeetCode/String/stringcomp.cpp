class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;
        while(i<n){
            char curr = chars[i];
            int count = 0;
            while(i<n && chars[i] == curr){
                count++;
                i++;
            }
            chars[index] = curr;
            index++;
            
            if(count > 1){
                string count_str = to_string(count);
                for(char &c: count_str){
                    chars[index] = c;
                    index++;
                }
            }
        }
        return index;
    }
};