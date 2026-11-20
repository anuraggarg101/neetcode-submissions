class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int curr_reach = 0;
        int max_reach = 0;
        int n = nums.size();
        if(n==1) return 0;

        for(int i=0;i<n;i++) {
            max_reach = max(max_reach, i + nums[i]);
            if(i == curr_reach) {
                curr_reach = max_reach;
                jumps++;
                if(curr_reach >= n-1) return jumps;
            }
        }
        return jumps;
    }
};
