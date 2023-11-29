class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, -1, 0, 1};

    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && 
            board[nrow][ncol] == 'O') {
                dfs(board, vis, nrow, ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for (int j= 0; j < n; j++) { //horizontal
            if (board[0][j] == 'O') {
                dfs(board, vis, 0, j);
            }
            if (board[m-1][j] == 'O') {
                dfs(board, vis, m-1, j);
            }
        }
        for (int i = 0; i < m; i++) { //vertical
            if (board[i][0] == 'O') {
                dfs(board, vis, i, 0);
            }
            if (board[i][n-1] == 'O') {
                dfs(board, vis, i, n-1);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

    }
};