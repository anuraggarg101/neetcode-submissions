class Solution {
private:
    using Index = pair<int, int>;
    static constexpr int dx[4] = {0, 1, -1, 0};
    static constexpr int dy[4] = {1, 0, 0, -1};
    
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<Index> q{};
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        const auto valid = [&](const int &x, const int &y) {
            return x >= 0 and x < n and y >= 0 and y < m;
        };

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            int dist = grid[i][j];
            for(int k=0;k<4;k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(valid(x, y) and grid[x][y] != -1) {
                    if(grid[x][y] > dist + 1) {
                        grid[x][y] = dist + 1;
                        q.push({x, y});
                    }
                }
                
            }
        }
    }
};
