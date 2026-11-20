/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> copy{};
    vector<Node*> node_copy{};
    void dfs(Node* node, Node* parent) {
        if(node == nullptr) return;

        int val = node->val;
        int idx = val - 1;
        bool is_visited = (node_copy[idx] != nullptr);

        if(is_visited) return;
        
        node_copy[idx] = new Node(val);


        auto &neighbors = node->neighbors;
        for(int i=0; i<neighbors.size(); i++) {
            int n_val = neighbors[i]->val;
            bool visited = (node_copy[n_val - 1] != nullptr);
            if(!visited) {
                dfs(neighbors[i], node_copy[idx]);
            }
            node_copy[idx]->neighbors.push_back(node_copy[n_val - 1]);
        }
        return;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        
        if(copy.find(node) != copy.end()) return copy[node];

        int val = node->val;
        Node* curr_copy = new Node(val);
        copy[node] = curr_copy;

        vector<Node*> &ns = node->neighbors;
        vector<Node*> cns{};

        for(int i=0; i<ns.size(); i++) {
            if(copy.count(ns[i]) == 0) {
                Node* neighbor = cloneGraph(ns[i]);
                copy[ns[i]] = neighbor;
                cns.push_back(neighbor);
            } else {
                cns.push_back(copy[ns[i]]);
            }
        }
        curr_copy->neighbors = cns;
        return curr_copy;

    }
};
