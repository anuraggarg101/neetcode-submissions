class Solution {
private:
    static constexpr int dx[4] = {1, 0, -1, 0};
    static constexpr int dy[4] = {0, -1, 0, 1};

    int n;
    int m;

    bool isvalid(int x, int y) {
        return (x >= 0) and (x < n) and (y >= 0) and (y<m);
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '-';

        for(int k=0;k<4;k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(isvalid(x, y) and grid[x][y] == '1') {
                dfs(grid, x, y);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        n = grid.size();
        m = grid[0].size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
