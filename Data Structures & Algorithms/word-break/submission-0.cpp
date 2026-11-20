class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        
        for(int i=n-1; i>=0; i--) {
            for(int j=i;j<n;j++) {
                if(dp[j+1] and dict.count(s.substr(i, j-i+1)) > 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
