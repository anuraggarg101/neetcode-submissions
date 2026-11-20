class Solution {
private:
    bool dfs(int node, int n, vector<int> &visited, vector<vector<int>> &adj_list) {
        if(visited[node] == 1) {
            return true;
        }

        if(visited[node] == 2) {
            return false;
        }

        visited[node] = 1;

        for(int i=0; i<adj_list[node].size(); i++) {
            if(dfs(adj_list[node][i], n, visited, adj_list)) {
                return true;
            }
        }
        visited[node] = 2;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(n, vector<int>());

        for(auto &edge:prerequisites) {
            int src = edge[1];
            int dest = edge[0];
            adj_list[src].push_back(dest);
        }

        vector<int> visited(n, 0);
        for(int i=0; i<n; i++) {
            if(dfs(i, n, visited, adj_list)) {
                return false;
            }
        }
        return true;
    }
};
