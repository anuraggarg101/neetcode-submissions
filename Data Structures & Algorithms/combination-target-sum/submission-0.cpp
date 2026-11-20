class Solution {
private:
    void helper(vector<int> &nums, int idx, int target, vector<int> &subset, vector<vector<int>> &res) {
        if(idx >= nums.size()) {
            return;
        }
        if(target == 0) {
            res.push_back(subset);
            return;
        }

        helper(nums, idx+1, target, subset, res);
        if(nums[idx] <= target) {
            subset.push_back(nums[idx]);
            helper(nums, idx, target - nums[idx], subset, res);
            subset.pop_back();            
        }
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res{};
        vector<int> subset{};
        helper(nums, 0, target, subset, res);
        return res;
    }
};
