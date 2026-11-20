class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        unordered_set<int> mp{};
        for(const auto&n:nums) {
            mp.insert(n);
        }

        int max_len = 1;

        for(int i=0;i<nums.size();i++) {
            int len = 1;
            int curr = nums[i];
            if(mp.find(curr) != mp.end()) {
                if(mp.find(curr - 1) == mp.end()) {
                    // might be a valid start
                    mp.erase(curr);
                    while(mp.find(curr+1) != mp.end()) {
                        mp.erase(curr+1);
                        curr += 1;
                        len += 1;
                    }
                }
            }
            max_len = max(len, max_len);

        }
        return max_len;
    }
};
