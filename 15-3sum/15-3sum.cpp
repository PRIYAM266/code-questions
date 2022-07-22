
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int target = (-1) * nums[i];
            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[l] + nums[r];
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    ans.push_back(triplet);
                    
                    while(l < r && nums[l] == triplet[1]) l++;
                    while(l < r && nums[r] == triplet[2]) r--;
                }
                while(i < n-1 && nums[i] == nums[i+1]) i++;
            }
        }
        return ans;
    }
};