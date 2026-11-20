class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        
        int ans = 0;
        for(int i=1;i<prices.size();i++) {
            int curr_profit = prices[i] - min_price;
            ans = max(ans, curr_profit);
            min_price = min(prices[i], min_price);
        }
        return ans;
    }
};
