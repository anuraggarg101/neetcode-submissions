class Solution {
private:
    void helper(vector<int> &nums, int idx, vector<int> subset, vector<vector<int>> &res) {
        if(idx == nums.size()) {
            res.push_back(subset);
            return;
        }

        helper(nums, idx+1, subset, res);
        subset.push_back(nums[idx]);
        helper(nums, idx+1, subset, res);
        subset.pop_back();
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{};
        vector<int> subset{};
        helper(nums, 0, subset, res);
        return res;
    }
};
