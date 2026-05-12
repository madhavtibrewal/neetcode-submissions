class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9);
        vector<int> col(9);
        vector<int> box(9);

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.') continue;

                int mask = 1 << (board[r][c] - 1);

                if(row[r] & mask || col[c] & mask || 
                    box[(r / 3) * 3 + (c / 3)] & mask){
                    return false;
                }

                row[r] = row[r] | mask;
                col[c] = col[c] | mask;
                box[(r / 3) * 3 + (c / 3)] = box[(r / 3) * 3 + (c / 3)] | mask;
            }
        }

        return true;

    }
};
