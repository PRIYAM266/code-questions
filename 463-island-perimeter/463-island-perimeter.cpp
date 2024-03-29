class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1)
            return 4;
        int ans = 0;
        vector<int> v(n*m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    if (j < m-1 && grid[i][j+1] == 1) {
                        ans -= 2;
                    }
                    if (i < n-1 && grid[i+1][j] == 1) {
                        ans -= 2;
                    }
                }
            }
        }
        return ans;
    }
};