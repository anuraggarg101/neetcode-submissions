class Solution {
private:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(dp[i][j] != -1) return dp[i][j];

        int n = s.length();
        int m = p.length();

        if(j == m) {
            return dp[i][j] = (i == n);
        }

        bool currMatch = (i < n) and (s[i] == p[j] or p[j] == '.');

        if(j+1<m and p[j+1] == '*') {
            return dp[i][j] = (solve(i, j+2,s,p,dp) or (currMatch and solve(i+1, j, s, p, dp)));
        }
        return dp[i][j] = currMatch and solve(i+1,j+1,s,p,dp);
    }
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        return solve(0,0,s,p,dp);
    }
};
