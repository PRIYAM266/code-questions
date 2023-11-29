class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, -1, 0, 1};

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol]
             && grid[nrow][ncol]) {
                 dfs(grid, vis, nrow, ncol);
             }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for (int j = 0; j < n; j++) { // horizontal 
            if (grid[0][j]) {
                dfs(grid, vis, 0, j);
            }
            if (grid[m-1][j]) {
                dfs(grid, vis, m-1, j);
            }
        }
        for (int i = 0; i < m; i++) { // vertical
            if (grid[i][0]) {
                dfs(grid, vis, i, 0);
            }
            if (grid[i][n-1]) {
                dfs(grid, vis, i, n-1);
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};