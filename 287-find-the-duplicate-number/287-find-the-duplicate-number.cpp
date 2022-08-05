class Solution {
public:
    int findDuplicate(vector<int>& nums) {
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