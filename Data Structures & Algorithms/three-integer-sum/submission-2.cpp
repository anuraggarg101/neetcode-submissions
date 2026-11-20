class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res{};
        for(int i=0;i<n-2;i++) {
            if(i > 0 and nums[i] == nums[i-1]) {
                continue;
            }

            int j = i+1;
            int k = n-1;
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    res.emplace_back(vector<int>{nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while(j<k and nums[j] == nums[j-1]) j++;
                    while(j<k and nums[k] == nums[k+1]) k--;
                    
                } else if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                }
            }
        }    
        return res;
    }
};
