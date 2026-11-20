class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        
        int max_len = 0;
        int max_freq = 0;
        int freq[26] = {0};

        for(int right = 0; right < s.length(); right++) {
            int win_len = right - left + 1;
            int r = s[right] - 'A';
            freq[r]++;
            max_freq = max(max_freq, freq[r]);
            bool is_window_valid = win_len - max_freq <= k;
            if(!is_window_valid) {
                freq[s[left] - 'A']--;
                left++;
            }
            win_len = right - left + 1;
            max_len = max(max_len, win_len);
        }
        return max_len;
    }
};
