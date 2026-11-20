class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr_reach = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            curr_reach = max(curr_reach, i + nums[i]);
            if(curr_reach >= (n-1)) return true;
            if(curr_reach == i) return false;
        }

        return false;
    }
};
