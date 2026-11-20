class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        static constexpr const auto kInsaneMax = 1e9;
        vector<vector<int>> dp(n+1, vector<int>(amount + 1, kInsaneMax));

        for(int i=1;i<=n;i++) {
            for(int j= 0; j<=amount; j++) {
                if(j == 0) {
                    // 0 coins required for 0 sum
                    dp[i][j] = 0;
                } else if(i == 0) {
                    // non zero sum and 0 coins, impossible case
                    continue;
                } else {
                    if(coins[i-1] <= j) {
                        // can use this coin
                        dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][amount] == kInsaneMax ? -1 : dp[n][amount];
    }
};
