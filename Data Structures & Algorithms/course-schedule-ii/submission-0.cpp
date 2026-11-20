class Solution {
private:
    bool dfs(int node, int n, vector<int> &visited, vector<int> &order, vector<vector<int>> &graph) {
        if(visited[node] == 1) return true;
        if(visited[node] == 2) return false;

        visited[node] = 1;
        for(int i=0; i<graph[node].size(); i++) {
            if(dfs(graph[node][i], n, visited, order, graph)) {
                return true;
            }
        }
        visited[node] = 2;
        order.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto &edge:prerequisites) {
            int src = edge[1];
            int dest = edge[0];
            graph[src].push_back(dest);
        }

        vector<int> visited(n, 0);
        vector<int> order{};
        for(int i=0; i<n; i++) {
            if(dfs(i, n, visited, order, graph)) {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};
