class Solution {
private:
    void solve(vector<int> &nums, int idx, int target, int curr_sum, int &ans) {
        if(idx == nums.size()) {
            ans += (curr_sum == target);
            return;
        }

        // add curr num
        curr_sum += nums[idx];
        solve(nums, idx+1, target, curr_sum, ans);

        // subtract curr num
        curr_sum -= 2*nums[idx];
        solve(nums, idx + 1, target, curr_sum, ans);
        return;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int curr_sum = 0;
        int ans = 0;
        solve(nums, 0, target, curr_sum, ans);
        return ans;
    }
};
