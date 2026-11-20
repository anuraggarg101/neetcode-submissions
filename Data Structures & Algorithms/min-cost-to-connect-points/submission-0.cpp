class Solution {
private:
    using QType = pair<int, int>; // {weight, dest}
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMst(n, false);

        minDist[0] = 0;
        int cost = 0;

        for(int edges_used=0; edges_used<n; edges_used++) {
            int u = -1;

            // find minimum cost node not yet in MST
            for(int i=0;i<n;i++) {
                if(!inMst[i] && (u == -1 || minDist[i] < minDist[u])) {
                    u = i;
                }
            }

            inMst[u] = true;
            cost += minDist[u];

            // relax all remaining nodes

            for(int i=0; i<n; i++) {
                if(!inMst[i]) {
                    int temp_cost = abs(points[u][0] - points[i][0]) + abs(points[u][1] - points[i][1]);

                    minDist[i] = min(minDist[i], temp_cost);
                }
            }
        }
        return cost;
    }
};
