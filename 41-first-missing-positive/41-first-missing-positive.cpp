class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        vector<bool> arr(1000000);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] < 1000000) {
                arr[nums[i]] = true;
            }
        }
        for (int i = 1; i < 1000000; i++) {
            if (!arr[i])
                return i;
        }
        return 0;
    }
};