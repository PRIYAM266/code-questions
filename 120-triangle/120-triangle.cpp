class Solution {
public:
    
    int f(int n, int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (i == n-1)
            return arr[n-1][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = arr[i][j] + f(n, i+1, j, arr, dp);
        int dg = arr[i][j] + f(n, i+1, j+1, arr, dp);
        return dp[i][j] = min(down, dg);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // return f(n, 0, 0, triangle, dp);
        for (int i = 0; i < n; i++) {
            dp[n-1][i] = triangle[n-1][i];
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, dg);
            }
        }
        return dp[0][0];
    }
};