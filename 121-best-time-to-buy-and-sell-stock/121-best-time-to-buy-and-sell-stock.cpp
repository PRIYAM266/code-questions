class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
        int mini = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};