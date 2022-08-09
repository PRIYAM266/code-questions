class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        while(i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                arr.push_back(nums1[i++]);
            } else {
                arr.push_back(nums2[j++]);
            }
        }
        while(i < n) {
            arr.push_back(nums1[i++]);
        }
        while(j < m) {
            arr.push_back(nums2[j++]);
        }
        int s = arr.size();
        float ans;
        if (s % 2 != 0) {
            ans = arr[s/2];
        }
        else {
            ans = (float)(arr[s/2]+arr[s/2 - 1]) / 2;
        }
        return ans;
    }
};