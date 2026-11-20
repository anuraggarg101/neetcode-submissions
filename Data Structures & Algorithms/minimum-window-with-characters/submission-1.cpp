class Solution {
private:
    template <typename T>
    bool isTPresent(const T& window, const T& freq) {
        for(int i=0;i<256;i++) {
            if(window[i] < freq[i]) return false;
        }
        return true;
    }

public:
    /*
    string minWindow(string s, string t) {
        vector<int> freq(256,0);
        for(auto &c:t) {
            freq[c]++;
        }

        vector<int> window(256,0);
        int start = 0, start_ = 0;
        int min_len = INT_MAX;
        int n = s.length();
        
        for(int i=0;i<n;i++) {
            window[s[i]]++;
            bool is_t_present = isTPresent(window, freq);
            while(is_t_present) {
                int curr_len = i - start + 1;
                if(curr_len < min_len) {
                    start_ = start;
                    min_len = curr_len;
                }
                window[s[start]]--;
                start++;
                is_t_present = isTPresent(window, freq);
            }            
        }

        return min_len == INT_MAX ? "" : s.substr(start_, min_len);
    }
    */
    string minWindow(string s, string t) {
        vector<int> freq(256,0);
        int required = 0;
        for(auto &c:t) {
            freq[c]++;
            required++;
        }

        int start = 0;
        int min_start = 0;
        int min_len = INT_MAX;
        int n = s.length();

        for(int i=0;i<n;i++) {
            if(freq[s[i]] > 0) {
                required--;
            }
            freq[s[i]]--;
            while(required == 0) {
                if(i-start+1 < min_len) {
                    min_len = i-start+1;
                    min_start = start;
                }
                freq[s[start]]++;
                if(freq[s[start]] > 0) {
                    required++;
                }
                start++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};
