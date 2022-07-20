class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v;
        int n = arr1.size();
        int m = arr2.size();
        int ma = *max_element(arr1.begin(), arr1.end());
        int mi = *min_element(arr1.begin(), arr1.end());
        vector<int> freq(ma - mi + 1);
        for (int i = 0; i < n; i++) {
            freq[arr1[i] - mi]++;
        }
        for (int i = 0; i < m; i++) {
            while(arr2[i] - mi >= 0 && freq[arr2[i] - mi] > 0) {
                v.push_back(arr2[i]);
                freq[arr2[i] - mi]--;
            }
        }
        for (int i = 0; i < ma-mi+1; i++) {
            while (freq[i] > 0) {
                v.push_back(i+mi);
                freq[i]--;
            }
        }
        return v;
    }
};