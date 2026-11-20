class Solution {
private:
    int expandAroundCentre(string &s, int left, int right) {
        while(left >= 0 and right < s.length()){
            if(s[left] != s[right]) break;
            left--;
            right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n == 1) return s;

        int start = 0;
        int maxLen = 1;

        for(int i=0;i<n;i++) {
            int len1 = expandAroundCentre(s, i, i);
            int len2 = expandAroundCentre(s, i, i+1);
            
            int len = max(len1, len2);
            if(len > maxLen) {
                maxLen = len;
                start = i- (len - 1)/2;
            }
        }
        return s.substr(start, maxLen);
    }
};
