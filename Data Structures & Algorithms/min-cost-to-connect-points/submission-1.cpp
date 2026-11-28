class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);

        minDist[0] = 0;
        
        int ans = 0;

        for(int i=0;i<n;i++) {
            
            int u = -1;
            for(int j=0;j<n;j++) {
                if(!visited[j] and (u == -1 or minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            // include u in mst
            visited[u] = true;
            ans += minDist[u];

            // update min dist of all other non included nodes
            for(int j=0; j<n; j++) {
                if(!visited[j]) {
                    int cost = abs(points[u][0] - points[j][0]) + abs(points[u][1] - points[j][1]);
                    minDist[j] = min(minDist[j], cost);
                }
            }
        }
        return ans;

    }
};
