class Solution {
private:
    vector<int> parent{};
    vector<int> size{};
    int num_components = 0;

    void init(int n) {
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
        num_components = n;
    }

    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;
        if(size[px] < size[py]) {
            swap(px, py);
        }

        parent[py] = px;
        size[px] += size[py];
        num_components--;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // approach 1: use dfs and count
        // approach 2: DSU
        init(n);
        for(auto &edge:edges) {
            unite(edge[0], edge[1]);
        }
        return num_components;
    }
};
