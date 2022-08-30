class Solution {
public:
    bool valid_row(vector<vector<char>>& board, int currRow, int currVal) {
        for (int i = 0; i < 9; i++) {
            if (board[currRow][i] == '0' + currVal)
                 return false;
        }
         return true;
    }

    bool valid_col(vector<vector<char>>& board, int currCol, int currVal) {
        for (int i = 0; i < 9; i++) {
            if (board[i][currCol] == '0' + currVal)
                return false;
        }
        return true;
    }

    bool valid_grid(vector<vector<char>>& board, int currRow, int currCol, int currVal) {
        int x = 3 * (currRow / 3);
        int y = 3 * (currCol / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ( board[x+i][y+j] == '0' + currVal )
                    return false;
            }
        }
        return true;
    }

    bool valid_cell(vector<vector<char>>& board, int currRow, int currCol, int currVal) {
        return valid_row(board, currRow, currVal) && valid_col(board, currCol, currVal)
            && valid_grid(board, currRow, currCol, currVal);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int c = 1; c <= 9; c++) {
                        if (valid_cell(board, i, j, c)) {
                            board[i][j] = '0' + c;
                        
                            if (isValidSudoku(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    //if at any place we can't place a value then not possible
                    return false;
                }
            }
        }
    
        //if there are all non zero values
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool tmp = isValidSudoku(board);
        return;
    }
};