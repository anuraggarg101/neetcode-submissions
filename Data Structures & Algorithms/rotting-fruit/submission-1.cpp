class Solution {
private:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    int n{};
    int m{};
    bool isValid(int i, int j) {
        return (i>=0) and (i < n) and (j >=0) and (j<m);
    }
    
    using Index = pair<int, int>;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<Index> q{};

        int fresh = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                } else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if(fresh == 0) return 0;

        int time_taken = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int s=0; s<sz; s++) {
                Index idx = q.front();
                q.pop();

                int i = idx.first;
                int j = idx.second;
                for(int k=0;k<4;k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(isValid(x, y) and grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                    
                }
            }
            time_taken++;
        }

        return fresh > 0 ? -1 : time_taken-1;
    }
};
