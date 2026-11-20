class Solution {
private:
    void helper(vector<int> &nums, int idx, int target, vector<int> &subset, vector<vector<int>> &res) {
        if(target == 0) {
            res.push_back(subset);
            return;
        }

        if(idx >= nums.size()) {
            return;
        }

        int orig_idx = idx;
        while(idx < nums.size() - 1 and nums[idx+1] == nums[idx]) {
            idx++;
        }
        helper(nums, idx + 1, target, subset, res);
        
        idx = orig_idx;
        if(nums[idx] <= target) {
            subset.push_back(nums[idx]);
            helper(nums, idx + 1, target - nums[idx], subset, res);
            subset.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res{};
        vector<int> subset{};
        helper(candidates, 0, target, subset, res);
        return res;
    }
};
