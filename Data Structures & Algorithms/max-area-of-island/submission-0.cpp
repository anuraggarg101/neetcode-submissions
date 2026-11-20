class Solution {
private:
    int n_{};
    int m_{};

    static constexpr const int kSides = 4;
    static constexpr const int dx[kSides] = {1, 0, -1, 0};
    static constexpr const int dy[kSides] = {0, 1, 0, -1};
    
    bool isValid(int i, int j) {
        return (i>=0) and (i<n_) and (j>=0) and (j<m_);
    }

    int dfs(vector<vector<int>> &grid, int r, int c) {
        if(grid[r][c] != 1) {
            return 0;
        }

        grid[r][c] = 2;
        int count = 1;
        for(int i=0;i<kSides; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if(isValid(x, y) and grid[x][y] == 1) {
                count += dfs(grid, x, y);
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n_ = grid.size();
        m_ = grid[0].size();

        int max_area = 0;
        for(int i=0; i<n_; i++) {
            for(int j=0; j<m_; j++) {
                if(grid[i][j] == 1) {
                    int curr_area = dfs(grid, i, j);
                    max_area = max(max_area, curr_area);
                }
            }
        }
        return max_area;
    }
};
