class Solution {
private:
    using QType = pair<int, pair<int, int>>; // {cost, {flights taken, airport}}
    static constexpr const int INF = 1e9;

    int solveDijkstra(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto &flight:flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to, price});
        }

        // costs[u][f] = cost of reaching u by taking f flights. so f+1 stops
        vector<vector<int>> costs(n, vector<int>(k+2, INF));
        priority_queue<QType, vector<QType>, greater<QType>> pq{};

        costs[src][0] = 0;
        pq.push({0, {0, src}});

        int ans = INF;

        while(!pq.empty()) {
            auto [node_cost, state] = pq.top();
            pq.pop();
            auto [steps, airport] = state;

            if(node_cost != costs[airport][steps]) {
                // outdated value
                continue;
            }

            if(airport == dst) {
                return node_cost;
            }

            if(steps == k+1) 
                continue;

            
            for(auto &[dest, cost]:adj[airport]) {
                int new_cost = node_cost + cost;
                int new_steps = steps + 1;

                if(new_cost < costs[dest][new_steps]) {
                    costs[dest][new_steps] = new_cost;
                    pq.push({new_cost, {new_steps, dest}});
                }
            }
        }
        return -1;

    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return solveDijkstra(n, flights, src, dst, k);
    }
};
