class Solution {
private:
    using Index = pair<int, int>;
    static constexpr int dx[4] = {1, 0, -1, 0};
    static constexpr int dy[4] = {0, 1, 0, -1};

    int n;
    int m;

    bool valid(int x, int y) {
        return x>=0 and x < n and y>=0 and y<m;
    }

    void traverse(const vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<Index> &q) { 
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            visited[r][c] = true;
            for(int k=0;k<4;k++) { 
                int x = r + dx[k];
                int y = c + dy[k];
                if(valid(x, y) and !visited[x][y] and heights[x][y] >= heights[r][c]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<Index> q{};

        for(int i=0;i<n;i++) {
            q.push({i,0});
        }
        for(int j=1;j<m;j++) {
            q.push({0, j});
        }
        traverse(heights, pacific, q);


        // q would be empty after above traverse
        for(int i=0;i<n;i++) {
            q.push({i,m-1});
        }
        for(int j=0;j<m-1;j++) {
            q.push({n-1, j});
        }
        traverse(heights, atlantic, q);

        vector<vector<int>> res{};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j] and atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }       
        return res;
        
    }
};
