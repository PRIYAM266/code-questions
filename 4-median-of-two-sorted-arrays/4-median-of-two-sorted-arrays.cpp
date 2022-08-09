class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // ios_base::sync_with_stdio(0);
        // cin.tie(nullptr);
        // cout.tie(nullptr);
        
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int n = nums1.size(), m = nums2.size();
        int begin1 = 0, end1 = n;
        while (begin1 <= end1) {
            int i1 = (begin1+end1)/2;
            int i2 = (n+m+1)/2 - i1;
            int max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
            int max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];
            int min1 = (i1 == n) ? INT_MAX : nums1[i1];
            int min2 = (i2 == m) ? INT_MAX : nums2[i2];
            if (max1 <= min2 && max2 <= min1) {
                if ((n+m) % 2 == 0) {
                    return ((double) min(min1, min2) + max(max1, max2))/2;
                } else {
                    return (double)max(max1, max2);
                }
            } 
            else if (max1 > min2) 
                end1 = i1-1;
            else 
                begin1 = i1+1;
        }
        return 0;
    }
};