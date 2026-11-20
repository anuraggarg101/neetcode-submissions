class Solution {
private:
    int robLinear(vector<int> &nums, int start, int end) {
        if(start > end) return 0;
       if(start == end) return nums[start];

       int prev2 = nums[start];
       int prev1 = max(nums[start], nums[start+1]);
       for(int i = start+2; i<=end; i++) {
        int curr = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
       }
       return prev1;
    //    int n = end - start + 1;
    //    if(n == 1) return nums[start];

    //    vector<int> dp(n, 0);
    //    dp[0] = nums[0];
    //    dp[1] = max(nums[0], nums[1]);
    //    for(int i=start+2; i<n; i++) {
    //     dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    //    } 
    //    return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
       int ans1 = robLinear(nums, 0, nums.size() - 2);
       int ans2 = robLinear(nums, 1, nums.size() - 1);
       return max(ans1, ans2);
       
    }
};
