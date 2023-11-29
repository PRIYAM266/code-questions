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
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m-1 || j == n-1) {
                    if (grid[i][j]) {
                        dfs(grid, vis, i, j);
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};