class Solution {
private:

public:
    int maxProduct(vector<int>& nums) {
        int max_prod = nums[0];
        int min_prod = nums[0];

        int ans = max_prod;

        int n = nums.size();
        for(int i=1; i<n; i++) {
            int curr_max = max_prod;
            int curr_min = min_prod;

            max_prod = max({nums[i], curr_max * nums[i], curr_min * nums[i]});
            min_prod = min({nums[i], curr_max * nums[i], curr_min * nums[i]});

            ans = max(ans, max_prod);    
        }
        return ans;
    }
};
