class Solution {
private:
    int solveByDijkstra(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       // for k nodes, i can use k+1 edges
       vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>()); // [node][edges_used]
       for(auto &flight:flights) {
        int src = flight[0];
        int dest = flight[1];
        int cost = flight[2];
        graph[src].push_back({dest, cost});
       }

       vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
       using QType = vector<int>; // cost, edges_used, node
       priority_queue<QType, vector<QType>, greater<QType>> pq{};
       pq.push({0, 0, src});
       dist[src][0] = 0;

       while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int cost = curr[0];
        int edges_used = curr[1];
        int node = curr[2];

        if(cost > dist[node][edges_used]) continue;

        if(node == dst) return cost;
        if(edges_used == k+1) {
            continue;
        } 

        for(auto &[nei, price] : graph[node]) {
            int new_cost = cost + price;
            if(new_cost  < dist[nei][edges_used + 1]) {
                dist[nei][edges_used + 1] = new_cost;
                pq.push({new_cost, edges_used + 1, nei});
            }
        }
       }
       return -1;
 
    }
    int solveByKruskal(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for(int i=0;i<k+1;i++) {
            // relax edges k+1 times since i can use max of k+1 edges

            vector<int> temp = dist;
            for(auto &flight:flights) {
                int src = flight[0];
                int dest = flight[1];
                int cost = flight[2];

                if(dist[src] == INT_MAX) 
                    continue;

                temp[dest] = min(temp[dest], dist[src]  + cost);                
            }
            dist =  temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return solveByKruskal(n, flights, src, dst, k);
        return solveByDijkstra(n, flights, src, dst, k);
    }
};
