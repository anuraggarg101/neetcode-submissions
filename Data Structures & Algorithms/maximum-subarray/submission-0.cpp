class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int max_so_far = INT_MIN;

        for(int i=0;i<nums.size(); i++) {
            curr_sum = max(nums[i], curr_sum + nums[i]);

            if(curr_sum > max_so_far) {
                max_so_far = curr_sum;
            }

        }
        return max_so_far;
    }
};
