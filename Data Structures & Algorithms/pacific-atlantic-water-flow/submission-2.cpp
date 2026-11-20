class Solution {
private:
    int n{};
    int m{};

    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    uint32_t visited_flag{};
    bool isValid(int i, int j) {
        return (i >=0) and (i < n) and (j >= 0) and (j < m);
    }

    void dfs(vector<vector<int>>& heights, vector<vector<uint32_t>>& visited, int r, int c) {
    //    if(visited[r][c] & visited_flag) return;

        visited[r][c] = visited[r][c] | visited_flag;
        
        for(int i=0; i<4; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if(isValid(x, y) and !(visited[x][y] & visited_flag) and heights[x][y] >= heights[r][c]) {
                dfs(heights, visited, x, y);
            }
        }
        return;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<uint32_t>> visited(n, vector<uint32_t>(m, 0));

        visited_flag = 1;
        // pacific left
        for(int i=0;i<n;i++) {
            if(!(visited[i][0] & visited_flag)) {
                dfs(heights, visited, i, 0);
            }
        }
        // pacific top
        for(int j=0;j<m;j++) {
            if(!(visited[0][j] & visited_flag)) {
                dfs(heights, visited, 0, j);
            }
        }

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        // cout << "\n";
        // cout << "\n";

        visited_flag = 2;
        // atlantic right
        for(int i=0;i<n;i++) {
            if(!(visited[i][m-1] & visited_flag)) {
                dfs(heights, visited, i, m-1);
            }
        }
        // atlantic bottom
        for(int j=0;j<m;j++) {
            if(!(visited[n-1][j] & visited_flag)) {
                dfs(heights, visited, n-1, j);
            }
        }

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        
        vector<vector<int>> res{};
        for(int i=0; i<n; i++) {
            for(int j=0;j<m;j++) {
                if(visited[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
