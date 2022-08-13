class Solution {
    
public:
    int lcs(string &s1, string &s2, int &n1, int &n2, int i, int j, vector<vector<int>> &dp) {
        if (i == n1 || j == n2){
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            return 1 + lcs(s1, s2, n1, n2, i+1, j+1, dp);
        }
        int take1 = lcs(s1, s2, n1, n2, i, j+1, dp);
        int take2 = lcs(s1, s2, n1, n2, i+1, j, dp);
        return dp[i][j] = max(take1, take2);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return lcs(text1, text2, n1, n2, 0, 0, dp);
    }
};