class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int end = 0;
        int n = s.length();

        int ans = 0;
        vector<int> freq(26,0);
        
        int max_freq = 0;
        for(end = 0; end < n; end++) {
            freq[s[end] - 'A']++;
            max_freq = max(max_freq, freq[s[end] - 'A']);
            int window_len = end - start + 1;
            while((window_len - max_freq > k) and (start <= end)) {
                freq[s[start] - 'A']--;
                window_len--;
                start++;
            }
            ans = max(ans, window_len);
        }
        return ans;
    }
};
