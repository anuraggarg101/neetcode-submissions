class Solution {
private:
    bool containsString(vector<int> &big_f, vector<int> &small_f) {
        for(int i=0;i<26;i++) {
            if(big_f[i] != small_f[i]) return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        
        int k = s1.length();

        if(s2.length() < k) 
            return false;


        vector<int> window(26,0);
        vector<int> freq(26,0);
        for(auto &c:s1) {
            freq[c - 'a']++;
        }

        int start = 0;
        for(int i=0;i<s2.length();i++) {
            window[s2[i] - 'a']++;
            if(i - start + 1 > k) {
                window[s2[start] - 'a']--;
                start++;
            }
            if(window == freq) return true;
        }
        return false;
    }
};
