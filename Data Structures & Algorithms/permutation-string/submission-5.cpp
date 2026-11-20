class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        int m = s1.length();
        if(n < m) return false;

        int freq[26] = {0};
        int required = m;
        for(const auto &c:s1) {
            freq[c - 'a']++;
        }

        int left = 0;
        for(int right=0; right<n; right++) {
            int r = s2[right] - 'a';
            freq[r]--;
            if(freq[r] >= 0) required--;
            

            int win_len = right - left + 1;
            if(win_len > m) {
                // shrink window from left
                freq[s2[left]-'a']++;
                if(freq[s2[left]-'a'] > 0) {
                    required++;
                }
                left++;
            }

            
            if(required == 0) return true;
        }
        return false;
    }
};
