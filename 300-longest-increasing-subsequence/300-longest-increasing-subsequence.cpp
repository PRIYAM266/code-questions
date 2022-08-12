class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int increase[n];
        increase[0] = 1;
        for (int i = 1; i < n; i++) {
            increase[i] = 1;
            for (int j = i-1; j >= 0; j--) {
                if (arr[j] >= arr[i])
                    continue;
            
                int possibleAns = increase[j] + 1;
                increase[i] = max(increase[i], possibleAns);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, increase[i]);
        
        }
        return ans;
        }
};