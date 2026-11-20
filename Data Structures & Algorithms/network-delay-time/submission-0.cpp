class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);

        vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());
        for(auto &edge:times) {
            int src = edge[0];
            int dest = edge[1];
            int time_ = edge[2];
            graph[src].push_back({dest, time_});
        }

        // dijkstra algo to find shortest distance from k to all other nodes
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};

        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for(int i=0; i<graph[node].size(); i++) {
                int dest = graph[node][i].first;
                int time_ = graph[node][i].second;
                if(dist[dest] > dist[node] + time_) {
                    dist[dest] = dist[node] + time_;
                    pq.push({dist[dest], dest});
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans = max(ans, dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
