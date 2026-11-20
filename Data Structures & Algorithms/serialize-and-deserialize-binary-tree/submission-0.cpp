/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> q{};
        q.push(root);

        while(!q.empty()) {
            TreeNode* tp = q.front();
            q.pop();
            if(tp == nullptr) {
                res += "#";
            } else {
                res += to_string(tp->val);
                q.push(tp->left);
                q.push(tp->right);
            }
            res += ",";
        }
        return res;
    }

    vector<string> tokenise(string &data) {
        vector<string> tokens{};
        stringstream ss(data);
        string token{};
        while(getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        return tokens;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> tokens = tokenise(data);
        if(tokens[0] == "#") return nullptr;
        queue<TreeNode*> q{};
        TreeNode *root = new TreeNode(stoi(tokens[0]));
        q.push(root);
        int idx = 1;
        while(!q.empty() and idx < tokens.size()) {
            TreeNode* tp = q.front();
            q.pop();

            // left child
            TreeNode* left = tokens[idx] == "#" ? nullptr : new TreeNode(stoi(tokens[idx]));
            tp->left = left;
            if(left) q.push(left);
            idx++;

            // left child
            TreeNode* right = tokens[idx] == "#" ? nullptr : new TreeNode(stoi(tokens[idx]));
            tp->right = right;
            if(right) q.push(right);
            idx++;

        }
        return root;
    }
};
