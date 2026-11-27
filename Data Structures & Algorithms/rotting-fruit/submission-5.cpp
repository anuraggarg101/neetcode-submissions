class Solution {
private:
    using Index = pair<int, int>;
    static constexpr int dx[4] = {0, 1, -1, 0};
    static constexpr int dy[4] = {1, 0, 0, -1};
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<Index, int>> q{};

        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        const auto valid = [&n, &m](int x, int y) {
            return x>=0 and x < n and y >=0 and y<m;
        };

        int ans = -1;
        while(!q.empty()) {
            auto [index, time] = q.front();
            q.pop();

            for(int k=0;k<4;k++) {
                int x = index.first + dx[k];
                int y = index.second + dy[k];
                if(valid(x,y) and grid[x][y] == 1) {
                    grid[x][y] = 2;
                    q.push({{x,y}, time + 1});
                    ans = max(ans, time + 1);
                    fresh--;
                }
            }
        }

        return (fresh > 0 ? -1 : ans);
    }



};
