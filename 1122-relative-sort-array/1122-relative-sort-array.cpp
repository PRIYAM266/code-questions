class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // vector<int> v;
        // int n = arr1.size();
        // int m = arr2.size();
        // int ma = *max_element(arr1.begin(), arr1.end());
        // int mi = *min_element(arr1.begin(), arr1.end());
        // vector<int> freq(ma - mi + 1);
        // for (int i = 0; i < n; i++) {
        //     freq[arr1[i] - mi]++;
        // }
        // for (int i = 0; i < m; i++) {
        //     while(arr2[i] - mi >= 0 && freq[arr2[i] - mi] > 0) {
        //         v.push_back(arr2[i]);
        //         freq[arr2[i] - mi]--;
        //     }
        // }
        // for (int i = 0; i < ma-mi+1; i++) {
        //     while (freq[i] > 0) {
        //         v.push_back(i+mi);
        //         freq[i]--;
        //     }
        // }
        // return v;
        int n = arr1.size();
        int m = arr2.size();
        vector<int> v;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr1[i]]++;
        }
        for (int i = 0; i < m; i++) {
            while (mp[arr2[i]] > 0) {
                v.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            while (it->second > 0) {
                v.push_back(it->first);
                it->second--;
            }
        }
        return v;
    }
};