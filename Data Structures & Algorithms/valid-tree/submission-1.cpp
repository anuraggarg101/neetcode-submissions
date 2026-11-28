class Solution {
private:
    vector<int> parent{};
    vector<int> size{};
    int num_components{};

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

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return true;
        if(size[px] < size[py]) {
            swap(px, py);
        }
        parent[py] = px;
        size[px] += py;
        num_components--;
        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        init(n);
        for(auto &edge:edges) {
            if(unite(edge[0], edge[1])) return false;
        }
        return num_components == 1;
    }
};
