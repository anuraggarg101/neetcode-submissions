class Solution {
private:
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
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return false;

        if(size[px] < size[py]) {
            swap(px, py);
        }
        parent[py] = px;
        size[px] += size[py];
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        init(n);
        for(auto &edge:edges)  {
            if(!unite(edge[0]-1, edge[1]-1)) {
                return edge;
            }
        }
        return {};
    }
};
