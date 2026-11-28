class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};

        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &time:times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n+1, 1e9);

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d != dist[u]) continue;

            for(auto &edge:adj[u]) {
                int dest = edge.first;
                int time = edge.second;
                if(dist[dest] > d + time) {
                    dist[dest] = d + time;
                    pq.push({dist[dest], dest});
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans = max(ans, dist[i]);
            if(dist[i] == 1e9) return -1;
        }
        return ans;
    }
};
