class Solution {
private:
    void solve(vector<int> &nums, int idx, int target, int curr_sum, int &ans, const vector<int> &suffix_sum) {
        if(idx == nums.size()) {
            ans += (curr_sum == target);
            return;
        }

        // add curr num
        bool can_add = (curr_sum + nums[idx] - suffix_sum[idx]) <= target;
        if(can_add) {
            curr_sum += nums[idx];
            solve(nums, idx+1, target, curr_sum, ans, suffix_sum);
            curr_sum -= nums[idx];
        }
        
        // subtract curr num
        bool can_subtract = (curr_sum - nums[idx] + suffix_sum[idx]) >= target;
        if(can_subtract) {
            curr_sum -= nums[idx];
            solve(nums, idx + 1, target, curr_sum, ans, suffix_sum);
        }
        return;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int curr_sum = 0;
        int ans = 0;
        vector<int> suffix_sum(nums.size(), 0);
        for(int i=nums.size()-2; i>=0; i--) {
            suffix_sum[i] += suffix_sum[i+1] + nums[i+1];
        }
        solve(nums, 0, target, curr_sum, ans, suffix_sum);
        return ans;
    }
};
