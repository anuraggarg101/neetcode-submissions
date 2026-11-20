class Solution {
private:
    void dfs(int node, int n, vector<bool> &visited, vector<vector<int>> &graph) {
        if(visited[node]) return;
        visited[node] = true;
        for(int i=0; i<graph[node].size(); i++) {
            if(!visited[graph[node][i]]) {
                dfs(graph[node][i], n, visited, graph);
            }
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto &edge:edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, n, visited, graph);
                count++;
            }
        }
        return count;
    }
};
