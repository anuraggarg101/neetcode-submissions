class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mp{};
        for(const auto &n:nums) {
            auto it = mp.find(n);
            if(it != mp.end()) return true;
            mp.insert(n);
        }
        return false;
    }
};