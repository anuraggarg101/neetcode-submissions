class Solution {
private:
    static constexpr const int dx[4] = {0, 1, 0, -1};
    static constexpr const int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int i, int j, int n, int m) {
        return (i>=0) and (i<n) and (j >=0 ) and (j<m);
    }


    void dfs(vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &dp, int n, int m) {
        if(dp[r][c] != -1) return;
        
        dp[r][c] = 1;

        int curr = 1;
        for(int k=0; k<4;k++) {
            int x = r + dx[k];
            int y = c + dy[k];
            if(isValid(x,y,n,m) and matrix[x][y] > matrix[r][c]) {
                dfs(matrix, x, y, dp, n, m);
                curr = max(curr, 1 + dp[x][y]);
            }
        }
        dp[r][c] = curr;
        return;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dp[i][j] == -1) {
                    dfs(matrix, i, j, dp, n, m);
                }
            }
        }

        int ans = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
