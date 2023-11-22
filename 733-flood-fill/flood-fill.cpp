class Solution {
public:
    void dfs(int row, int col, int newColor, int initialColor, vector<vector<int>>& image,
    vector<vector<int>>& ans, int delrow[], int delcol[]) {
        int m = image.size(), n = image[0].size();
        ans[row][col] = newColor;

        for (int i = 0; i < 4; i++) {
            
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor) {
                    dfs(nrow, ncol, newColor, initialColor, image, ans, delrow, delcol);
                }
        
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int initialColor = image[sr][sc];
        int delrow[] = {0, -1, 0, 1};
        int delcol[] = {-1, 0, 1, 0}; 
        dfs(sr, sc, color, initialColor, image, ans, delrow, delcol);
        return ans;
    }
};