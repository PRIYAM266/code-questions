class Solution {
public:
    
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j]) {
            return 1 + f(i-1, j-1, s1, s2, dp);
        }
        return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
    }
    
    int f1 (int n, string &s1, string &s2) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] =  1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    
    int f2(string &text1, int i, int j, vector<vector<int>> &dp)
    {
        if(i > j)  
            return 0;
        if(i == j) 
            return 1;
        if(dp[i][j] != -1)   
            return dp[i][j];
        
        if(text1[i] == text1[j])  
            return dp[i][j] = 2 + f2(text1,i+1,j-1,dp);
         
        return dp[i][j] = max(f2(text1,i+1,j,dp),f2(text1,i,j-1,dp));
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // string st = s;
        // reverse(s.begin(), s.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f(n-1, n-1, st, s, dp);
        // return f1(n, st, s);
        return f2(s, 0, n-1, dp);
    }
};