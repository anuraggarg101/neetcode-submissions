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
        if(s2.length() < s1.length()) 
            return false;

        vector<int> f1(26,0);
        for(auto &c:s1) {
            f1[c - 'a']++;
        }

        int start = 0;
        int end = 0;
        vector<int> freq(26,0);

        
        while(end < s2.length()) {
            freq[s2[end] - 'a']++;
            while(start  < s2.length()  and freq[s2[start] - 'a'] > f1[s2[start] - 'a']) {
                freq[s2[start] - 'a']--;
                start++;
            }
            if(containsString(freq, f1)) {
                return true;
            }
            end++;
        }
        return false;
    }
};
