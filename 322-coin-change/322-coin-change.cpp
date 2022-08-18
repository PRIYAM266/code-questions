class Solution {
public:
    
    int f(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e8;
        }
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int pick = 1e8;
        if (coins[i] <= amount) {
            pick = 1 + f(i, amount - coins[i], coins, dp);
        }
        int not_pick = 0 + f(i-1, amount, coins, dp);
        
        return dp[i][amount] = min(pick, not_pick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        if (ans == 1e8)
            return -1;
        return ans;
    }
};