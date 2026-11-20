class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = nums.size() == 0 ? 0 : 1;

        for(auto &n:st) {
            // is start of sequence
            if(st.find(n-1) == st.end()) {
                int curr = n;
                int len = 1;
                while(st.find(curr+1) != st.end()) {
                    len++;
                    curr++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
