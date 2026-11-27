class Solution {
private:
    static constexpr int dx[4] = {0, 1, 0, -1};
    static constexpr int dy[4] = {1, 0, -1, 0};
    
    int n;
    int m;
    
    bool valid(int x, int y) {
        return (x >= 0) and (x < n) and (y >= 0) and (y < m);
    }

    int dfs(vector<vector<int>> &grid, int r, int c) {

        int area = 1;
        grid[r][c] = 0;
        for(int k=0; k<4; k++) {
            int x = r + dx[k];
            int y = c + dy[k];
            if(valid(x, y) and grid[x][y] == 1) {
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();

        int max_area = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};
