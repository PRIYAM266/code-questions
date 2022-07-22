class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        int n = costs.size()/2;
        for (int i = 0; i < 2*n; i++) {
            sum += costs[i][0];
            costs[i][0] -= costs[i][1]; 
        }
        sort(costs.begin(), costs.end(), greater<>());
        for (int i = 0; i < n; i++) {
            sum -= costs[i][0];
        }
        return sum;
    }
};