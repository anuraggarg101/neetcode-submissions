class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.length();
        int n = s.length();

        if(m > n) return "";

        unordered_map<char, int> freq{};
        int required = 0;
        for(const auto &c:t) {
            freq[c]++;
            required++;
        }

        int left = 0;
        int min_len = n+1;

        int start = -1;

        for(int right = 0; right < n; right++) {
            freq[s[right]]--;
            if(freq[s[right]] >= 0) {
                required--;
            }

            while(required == 0) {
                int curr_len = right - left + 1;
                if(curr_len < min_len) {
                    min_len = curr_len;
                    start = left;
                }

                // try shrinking from left
                if(freq[s[left]] >= 0) {
                    required++;
                }
                freq[s[left]]++;
                left++;
            }
        }

        return (start == -1 ? "" : s.substr(start, min_len));

    }
};
