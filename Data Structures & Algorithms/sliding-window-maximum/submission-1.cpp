class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq{};
        int n = nums.size();

        vector<int> res{};
        for(int i=0;i<n;i++) {
            // remove expired elems
            while(!dq.empty() and i - dq.front() >= k) {
                dq.pop_front();
            }

            // remove smaller elems from back
            while(!dq.empty() and nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
