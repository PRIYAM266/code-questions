class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])
            return a[0] > b[0];
        
        return a[1] < b[1];
        
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
        sort(properties.begin(), properties.end(), cmp);
        int maxi = INT_MIN;
        int n = properties.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if ( maxi > properties[i][1])
                ans++;
                
            else 
                maxi = properties[i][1];
        }
        
        return ans;
        
    }
};