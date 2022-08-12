class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = arr.size();
        int ans = 1;
        vector<int> increase(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (arr[j] >= arr[i])
                    continue;
            
                int possibleAns = increase[j] + 1;
                increase[i] = max(increase[i], possibleAns);
            }
            ans = max(ans, increase[i]);
        }
        
        return ans;
        }
};