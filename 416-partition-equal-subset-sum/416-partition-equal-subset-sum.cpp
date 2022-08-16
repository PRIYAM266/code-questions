class Solution {
public:
    bool f(vector<int>& arr, int i, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == 0) return (target == arr[0]);
        if (dp[i][target] != -1) return dp[i][target];
        bool take = false, not_take = false;
        not_take = f(arr, i-1, target, dp);
        if (arr[i] <= target) 
            take = f(arr, i-1, target-arr[i], dp);
        return dp[i][target] = (take || not_take);
    }
    
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2 == 1) return false;
        int target = s/2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(nums, n-1, target, dp);
    }
};