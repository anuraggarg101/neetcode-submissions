class Solution {
private:
    bool anyDuplicate(const unordered_map<char, int> &mp) {
        for(const auto &it:mp) {
            if(it.second > 1) {
                return true;
            }
        }
        return false;
    }
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int len = 0;
        int n = s.length();
        unordered_map<char, int> st{};
        int max_len = 0;
        while(end < n) {
            st[s[end]]++;
            while(anyDuplicate(st)) {
                st[s[start]]--;
                start++;
            }

            int curr_len = end - start + 1;
            max_len = max(max_len, curr_len);
            end++;
        }
        return max_len;
    }
};
