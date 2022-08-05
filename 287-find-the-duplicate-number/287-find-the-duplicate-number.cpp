class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = nums.size();
        vector<bool> arr(n+1);
        for (int i = 0; i < n; i++) {
            if (arr[nums[i]])
                return nums[i];
            arr[nums[i]] = true;
        }
        return -1;
    }
};