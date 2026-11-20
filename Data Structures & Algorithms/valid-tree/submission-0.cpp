class Solution {
private:
    struct DSU {
        vector<int> parent{};
        vector<int> size{};

        void init(int n) {
            parent.resize(n);
            size.resize(n);
            for(int i=0; i<n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int a) {
            if(a == parent[a]) return a;
            return parent[a] = find(parent[a]);
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
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        DSU dsu{};
        dsu.init(n);
        
        int count = n;
        for(auto &edge:edges) {
            int a = edge[0];
            int b = edge[1];
            if(dsu.unite(a, b)) {
                count--;
            } else {
                return false;
            }
        }
        return (count == 1);
    }
};
