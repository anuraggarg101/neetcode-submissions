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
    vector<Node*> node_copy{};

    void dfs(Node* node, Node* parent) {
        if(node == nullptr) return;

        int val = node->val;
        int idx = val - 1;
        bool is_visited = (node_copy[idx] != nullptr);

        if(is_visited) return;
        
        node_copy[idx] = new Node(val);
        // if(parent != nullptr) {
        //     parent->neighbors.push_back(node_copy[idx]);
        // }

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
        for(int i=0;i<100;i++) {
            node_copy.push_back(nullptr);
        }
        dfs(node, nullptr);
        return node_copy[0];

    }
};
