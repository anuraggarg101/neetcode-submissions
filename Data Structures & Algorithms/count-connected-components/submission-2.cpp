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
    int countByDfs(int n, vector<vector<int>>& edges) {
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

    struct DSU {
        vector<int> parent{};
        vector<int> size{};

        void init(int n) {
            size.resize(n);
            parent.resize(n);
            for(int i=0; i<n; i++) {
                size[i] = 1;
                parent[i] = i;
            }
        }

        int findParent(int i) {
            if(i == parent[i]) {
                return i;
            }
            return parent[i] = findParent(parent[i]);
        }

        bool unite(int a, int b) {
            int pa = findParent(a);
            int pb = findParent(b);

            if(pa == pb) {
                // already same union
                return false;
            }

            int ra = size[pa];
            int rb = size[pb];

            if(ra < rb) {
                parent[pa] = pb;
                size[pb] += size[pa];
            } else {
                parent[pb] = pa;
                size[pa] += size[pb];                
            }
            
            return true;
        }

        bool isSame(int a, int b) {
            return findParent(a) == findParent(b);
        }

        int componentSize(int x) {
            return size[findParent(x)];
        }
    };


    
    int countByDsu(int n, vector<vector<int>>& edges) {
        DSU dsu{};
        dsu.init(n);
        int components = n;
        for(auto &edge:edges) {
            int a = edge[0];
            int b = edge[1];
            if(dsu.unite(a, b)) {
                components--;
            }
        }
        return components;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // return countByDfs(n, edges);
        return countByDsu(n, edges);
    }
};
