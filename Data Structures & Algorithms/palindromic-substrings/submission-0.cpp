class Solution {
private:
    int expand(string &s, int left, int right) {
        int count = 0;
        while(left >= 0 and right<s.length() and s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += expand(s, i, i);
            ans += expand(s, i, i+1);
        }
        return ans;
    }
};
