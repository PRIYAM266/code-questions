class Solution {
public:
    
    int f(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == s[j])
            return 2 + f(i+1, j-1, s, dp);
        
        return dp[i][j] = max(f(i+1, j, s, dp), f(i, j-1, s, dp));
    }
    
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int pal = f(0, n-1, s, dp);
        return n - pal;
    }
};