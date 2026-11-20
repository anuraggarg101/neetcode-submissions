class Solution {
private:
    void helper(vector<int> &nums, int idx, vector<int> &subset, vector<vector<int>> &res) {
        if(idx == nums.size()) {
            res.push_back(subset);
            return;
        }

        int i = idx;
        while(i < nums.size() -1  and nums[i] == nums[i+1]) {
            i++;
        }
        helper(nums, i+1, subset, res);

        // helper(nums, idx + 1, subset, res);
        subset.push_back(nums[idx]);
        helper(nums, idx + 1, subset, res);
        subset.pop_back();
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset{};
        vector<vector<int>> res{};
        helper(nums, 0, subset, res);
        return res;
    }
};
