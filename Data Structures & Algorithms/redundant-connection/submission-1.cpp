class Solution {
private:
    struct DSU {
        vector<int> parent{};
        vector<int> size{};

        void init(int n) {
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            if(x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {
            int pa = find(a);
            int pb = find(b);

            if(pa == pb) return false;

            if(size[pa] < size[pb]) {
                swap(pa, pb);
            }

            parent[pb] = pa;
            size[pa] += size[pb];
            return true;
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu{};
        int n = edges.size();
        dsu.init(n);
        for(auto &edge:edges) {
            int a = edge[0] - 1;
            int b = edge[1] - 1;
            if(!dsu.unite(a, b)) {
                return edge;
            }
        }
        return {};
    }
};
