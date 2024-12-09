class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9], col[9] , box[9];
        for(int r = 0 ; r < 9 ; r++){
            for(int c = 0 ; c < 9 ; c++){
                if(board[r][c] == '.') continue;
                char value = board[r][c];
                int boxI = (r/3)*3+(c/3);
                if(row[r].count(value) || col[c].count(value) || box[boxI].count(value)) return false;
                row[r].insert(value);
                col[c].insert(value);
                box[boxI].insert(value);
            }
        }
        return true;
    }
};