class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        using QType = pair<int, pair<int, int>>; // {minimum time, {row, col}}
        priority_queue<QType, vector<QType>, greater<QType>> pq{};
        
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        const auto valid = [n](int x, int y) {
            return x>=0 and x < n and y>=0 and y<n;
        };

        while(!pq.empty()) {
            auto [time, index] = pq.top();
            pq.pop();
            auto [r, c] = index;

            if(r == n-1 and c == n-1) {
                return time;
            }

            for(int k=0;k<4;k++) {
                int x = r + dr[k];
                int y = c + dc[k];
                if(valid(x, y)) {
                    int new_time = max(time, grid[x][y]);
                    if(new_time < dist[x][y]) {
                        dist[x][y] = new_time;
                        pq.push({new_time, {x,y}});

                    }
                }
            }
        }
        return -1;
    }
};
