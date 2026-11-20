class Solution {
private:
#define _VISITED_ '2';
    int n_{};
    int m_{};
    
    static constexpr const int kSides = 4;
    static constexpr const int dx[kSides] = {1, 0, -1, 0};
    static constexpr const int dy[kSides] = {0, 1, 0, -1};
    
    bool isValidIndex(int r, int c) {
        return (r >= 0) and (r < n_) and (c >= 0) and (c < m_);
    }

    void dfs(vector<vector<char>> &grid, int r, int c) {
        if(grid[r][c] != '1') return;

        grid[r][c] = _VISITED_;
        for(int i=0;i<kSides;i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if(isValidIndex(x,y) and grid[x][y] == '1') {
                dfs(grid, x, y);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        n_ = grid.size();
        m_ = grid[0].size();
        for(int i=0;i<n_;i++) {
            for(int j=0;j<m_;j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
