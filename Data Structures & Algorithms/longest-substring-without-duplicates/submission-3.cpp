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
        st.reserve(256);
        int max_len = 0;
        while(end < n) {
            st[s[end]]++;
            bool duplicate_added = (st[s[end]] > 1);
            if(duplicate_added) {
                while(true) {
                    st[s[start]]--;
                    start++;
                    if(s[start - 1] == s[end]) break;
                }    
            }
            
            int curr_len = end - start + 1;
            max_len = max(max_len, curr_len);
            end++;
        }
        return max_len;
    }
};
