class Solution {
public:
    
    int f(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == 0) {
            /* if at last index sum is 0 and number is also 0 then whether you take it or not                   you will get the ans 
            */
            
            if (target == 0 && arr[0] == 0)
                return 2;
            
            /* if at last index sum is 0 then whatever will be the number there will be 1                       choice
                if at last index sum is equal to that number at last index there is only                        choice to take it
            */
            if (target == 0 || arr[0] == target)  
                return 1;
            return 0;
        }  
        if (dp[i][target] != -1)
            return dp[i][target];
        
        int not_take = 0 + f(i-1, target, arr, dp);
        int take = 0;
        if (arr[i] <= target)
            take = f(i-1, target - arr[i], arr, dp);
        return dp[i][target] = take + not_take;
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum || (target - sum) % 2) 
            return 0;
        int newTarget = (sum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(newTarget+1, -1));
        return f(n-1, newTarget, nums, dp);
    }
};