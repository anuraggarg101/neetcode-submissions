class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp{};
        int n,rem;
        for(int i=0;i<nums.size();i++) {
            n = nums[i];
            rem = target - n;
            auto it = mp.find(rem);
            if(it != mp.end()) {
                int x = it->second;
                return {x, i};
            }
            mp[n] = i;
        }
        return {0,0};
    }
};
