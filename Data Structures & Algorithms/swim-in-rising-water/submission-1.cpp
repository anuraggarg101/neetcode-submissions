class Solution {
private:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    
    bool isValid(int i, int j, int n) {
        return (i>=0) and (i < n) and (j >=0) and (j<n);
    }
    
    struct DSU {
        vector<int> parent{};
        vector<int> size{};

        void init(int n) {
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            if(x == parent[x]) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {
            int pa = find(a);
            int pb = find(b);

            if(pa == pb) {
                return false;
            }

            if(size[pa] < size[pb]) {
                swap(pa, pb);
            }
            parent[pb] = pa;
            size[pa] += size[pb];
            return true;
        }
    };

    int solveByDsu(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu{};
        dsu.init(n*n);

        vector<pair<int, int>> pos(n*n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                pos[grid[i][j]] = {i,j};
            }
        }

        vector<vector<int>> active(n, vector<int>(n, false));
        
        for(int time=0; time<n*n; time++) {
            auto [r, c] = pos[time];
            active[r][c] = true;

            int id1 = n*r + c;
            for(int k=0;k<4;k++) {
                int x = r + dx[k];
                int y = c + dy[k];

                if(isValid(x, y, n) and active[x][y]) {
                    int id2 = n*x + y;
                    dsu.unite(id1, id2);
                }
            }

            if(dsu.find(0) == dsu.find(n*n-1)) {
                //start and end included
                return time;
            }
        }
        return -1;
    }

    int solveByDijkstra(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        using QType = vector<int>;
        priority_queue<QType, vector<QType>, greater<QType>> pq{};

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(cost < dist[r][c]) 
                continue;
            
            if(r == n-1 and c == n-1) return cost;
            for(int k=0;k<4;k++) {
                int x = r + dx[k];
                int y = c + dy[k];
                if(isValid(x, y, n)) {
                    int new_cost = max(cost, grid[x][y]);
                    if(new_cost < dist[x][y]) {
                        dist[x][y] = new_cost;
                        pq.push({new_cost, x, y});
                    }
                }
            }
        }

        return -1;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        return solveByDijkstra(grid);
        return solveByDsu(grid);    
        
    }
};
