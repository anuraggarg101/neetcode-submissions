class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];
        for(int i=2; i<n; i++) {
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);

        // vector<int> dp(n+1, 0);
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // for(int i=2;i<n;i++) {
        //     dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        // }
        // dp[n] = min(dp[n-1], dp[n-2]);
        // return dp[n];
    }
};
