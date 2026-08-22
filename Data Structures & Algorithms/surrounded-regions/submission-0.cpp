class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O'){
                capture(board, i, 0, rows, cols);
            }
            if(board[i][cols - 1] == 'O'){
                capture(board, i, cols - 1, rows, cols);
            }
        }
        for(int j = 0; j < cols; j++){
            if(board[0][j] == 'O'){
                capture(board, 0, j, rows, cols);
            }
            if(board[rows - 1][j] == 'O'){
                capture(board, rows - 1, j, rows, cols);
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void capture(vector<vector<char>>& board, int i, int j, int rows, int cols){
        if( i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != 'O'){
            return; 
        }

        board[i][j] = 'T';
        capture(board, i + 1, j, rows, cols);
        capture(board, i - 1, j, rows, cols);
        capture(board, i, j + 1, rows, cols);
        capture(board, i, j - 1, rows, cols);
    }
};
