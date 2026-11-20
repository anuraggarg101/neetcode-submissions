class Solution {
private:
    using Index = pair<int, int>; // i,j
    static constexpr const int dx[4] = {1, 0, 0, -1};
    static constexpr const int dy[4] = {0, 1, -1, 0};
    int n{};
    int m{};

    bool isValid(int r, int c) {
        return (r >= 0) and (c >= 0) and (r < n) and (c < m);
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<Index> q{};
        n = grid.size();
        m = grid[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {
            Index idx = q.front();
            q.pop();
            int i = idx.first;
            int j = idx.second;
            for(int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(isValid(x, y) and grid[x][y] > grid[i][j] + 1) {
                    grid[x][y] = grid[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
        return;
    }
};
