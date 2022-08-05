class Solution {
public:
    int rob(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 1) {
            return arr[0];
        }
        if (n == 2) {
            return max(arr[0], arr[1]);
        }
        vector<int> output(n);
        output[0] = arr[0];
        output[1] = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++) {
            output[i] = max(output[i-1], output[i-2] + arr[i]);
        }
    
        return output[n-1];
    }
};