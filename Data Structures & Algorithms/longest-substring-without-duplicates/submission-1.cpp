class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);

        int start = 0;
        int end = 0;
        int n = s.length();
        int ans = 0;
        while(end < n) {
            bool is_repeat = freq[s[end]] > 0;
            while(is_repeat) {
                freq[s[start]]--;
                start++;
                is_repeat = freq[s[end]] > 0;
            }
            freq[s[end]]++;
            int curr_len = end - start + 1;
            ans = max(curr_len, ans);
            end++;
        }
        return ans;
    }
};
