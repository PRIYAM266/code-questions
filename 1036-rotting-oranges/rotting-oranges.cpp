class Solution {
public:
    void bfs(queue< pair< pair<int, int>, int>>& q, int& time, vector<vector<int>>& grid,
        vector<vector<int>>& vis) {
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, -1, 0, 1};
            int m = grid.size(), n = grid[0].size();

            while(!q.empty()) {
                int row = q.front().first.first;
                int col = q.front().first.second;
                int t = q.front().second;
                time = max(time, t);
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
                        vis[nrow][ncol] == 1 && grid[nrow][ncol] == 1) {
                            q.push({{nrow, ncol}, t + 1});
                            vis[nrow][ncol] = 2;
                        }
                }
            }
        }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        queue< pair< pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                vis[i][j] = grid[i][j];
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }
        int tm = 0;
        
        bfs(q, tm, grid, vis);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 1)
                    return -1;
            }
        }
        return tm;

    }
};