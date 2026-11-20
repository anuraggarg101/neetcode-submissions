class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<int> hold(n, 0);
        // vector<int> sold(n, 0);
        // vector<int> rest(n, 0);
        

        // hold[0] = -prices[0];

        // for(int i=1;i<n;i++) {
        //     hold[i] = max(hold[i-1], rest[i-1] - prices[i]);
        //     sold[i] = hold[i-1] + prices[i];
        //     rest[i] = max(rest[i-1], sold[i-1]);
        // }
        // return max(rest[n-1], sold[n-1]);

        int hold = -prices[0];
        int rest = 0;
        int sold = 0;
        for(int i=1;i<n;i++) {
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_rest = rest;

            hold = max(prev_hold, prev_rest - prices[i]);
            sold = prev_hold + prices[i];
            rest = max(prev_rest, prev_sold);
        }
        return max(rest, sold);
        
    }
};
