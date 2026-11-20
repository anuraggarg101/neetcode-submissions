class Solution {
private:
    // void solve(vector<int> &nums, int idx, int target, int curr_sum, int &ans, const vector<int> &suffix_sum) {
    //     if(idx == nums.size()) {
    //         ans += (curr_sum == target);
    //         return;
    //     }

    //     // add curr num
    //     bool can_add = (curr_sum + nums[idx] - suffix_sum[idx]) <= target;
    //     if(can_add) {
    //         curr_sum += nums[idx];
    //         solve(nums, idx+1, target, curr_sum, ans, suffix_sum);
    //         curr_sum -= nums[idx];
    //     }
        
    //     // subtract curr num
    //     bool can_subtract = (curr_sum - nums[idx] + suffix_sum[idx]) >= target;
    //     if(can_subtract) {
    //         curr_sum -= nums[idx];
    //         solve(nums, idx + 1, target, curr_sum, ans, suffix_sum);
    //     }
    //     return;
    // }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // int curr_sum = 0;
        // int ans = 0;
        // vector<int> suffix_sum(nums.size(), 0);
        // for(int i=nums.size()-2; i>=0; i--) {
        //     suffix_sum[i] += suffix_sum[i+1] + nums[i+1];
        // }
        // solve(nums, 0, target, curr_sum, ans, suffix_sum);
        // return ans;

        /*
        p = sum of numbers assigned  + sign
        n = sum of numbers assigned - sign
        
        p - n = target
        p + n = total_sum
        p = (target + total_sum ) / 2;

        */
        
        int total_sum = 0;
        for(auto &n:nums) {
            total_sum += n;
        }

        if((total_sum + target) % 2 != 0) return 0;

        int sum =  (total_sum + target) / 2;
        
        // find number of subset with sum = sum;

        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for(auto &n:nums) {
            for(int j=sum; j>=n;j--) {
                dp[j] += dp[j-n];
            }
        }
        return dp[sum];
    }
};
