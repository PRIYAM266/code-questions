class Solution {
public:
    int rob(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 1) {
            return arr[0];
        }
        if (n == 2) {
            return max(arr[0], arr[1]);
        }
        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++) {
            int take = dp[i-2] + arr[i];
            int not_take = 0 + dp[i-1];
            dp[i] = max(take, not_take);
        }
    
        return dp[n-1];
    }
};