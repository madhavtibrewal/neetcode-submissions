class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(backtrack(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return backtrack(board, word, 0, 0, 0);
    }
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int k){
        if(k >= word.size()) return true;

        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = backtrack(board, word, i + 1, j, k + 1) || backtrack(board, word, i, j + 1, k + 1) || backtrack(board, word, i, j - 1, k + 1) || backtrack(board, word, i - 1, j, k + 1);

        board[i][j] = temp;

        return found;

    }
};

