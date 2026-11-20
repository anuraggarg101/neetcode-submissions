class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0,j=0,k=0;
        int n = nums.size();

        vector<vector<int>> res{};
        while(i<n-2) {
            
            j = i+1;
            k = n-1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j < k  and nums[k-1] == nums[k]) {
                        k--;
                    }
                    while(j < k  and nums[j+1] == nums[j]) {
                        j++;
                    }
                    k--;
                    j++;
                    continue;
                } 
                
                

                if(sum > 0) {                
                    while(j < k  and nums[k-1] == nums[k]) {
                        k--;
                    }
                    k--;
                } else {
                    while(j < k  and nums[j+1] == nums[j]) {
                        j++;
                    }
                    j++;
                }
            } 

            while(i < j  and nums[i+1] == nums[i]) {
                i++;
            }
            i++;
        }
        return res;
    }
};
