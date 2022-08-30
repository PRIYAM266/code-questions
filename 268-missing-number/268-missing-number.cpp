class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
    	
        int n = nums.size();
        int numsXor = 0;
        for (int i = 0; i < n; i++) {
            numsXor ^= nums[i];
        }
        int naturalXor = 0;
        
        if (n % 4 == 0)
            naturalXor = n;
        else if (n % 4 == 1)
            naturalXor = 1;
        else if (n % 4 == 2)
            naturalXor = n+1;
        else 
            naturalXor = 0;
        
        return naturalXor ^ numsXor;
    }
};