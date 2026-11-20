class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        
        int a = 1;
        int b = 2;
        
        // vector<int> dp(n, 0);
        // dp[0] = 1;
        // dp[1] = 2;
        for(int i=2;i<n;i++) {
            int temp = a;
            a = b;
            b = b + temp;
            // dp[i] = dp[i-1] + dp[i-2];
        }
        return b;
    }
};
