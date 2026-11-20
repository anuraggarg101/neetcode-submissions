class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails{};

        for(auto &x:nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if(it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }        
        return tails.size();
        // int n = nums.size();
        // if(n == 0) return 0;

        // int max_len = 1;
        // vector<int> dp(n, 1);
        // for(int i=0;i<n;i++) {
        //     for(int j=i; j>=0; j--) {
        //         if(nums[j] < nums[i] and dp[i] < dp[j] +1) {
        //             dp[i] = dp[j] + 1;
        //             max_len = max(max_len, dp[i]);
        //         }
        //     }
        // }
        // return max_len;
    }
};
