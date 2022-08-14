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
        // vector<int> dp(n);
        int prev2 = arr[0];
        int prev1 = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++) {
            int take = prev2 + arr[i];
            int not_take = 0 + prev1;
            int curr = max(take, not_take);
            prev2 = prev1;
            prev1 = curr;
        }
    
        return prev1;
    }
};