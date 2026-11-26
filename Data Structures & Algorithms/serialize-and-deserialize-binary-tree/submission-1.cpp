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
        if(!root) return "";
        string result;
        queue<TreeNode*> q{};
        q.push(root);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            if(!result.empty()) result += ",";
            if(!node) {
                result += "null";
                continue;
            }
            result += to_string(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string token;
        
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(!getline(ss, token, ',')) break;

            if(token != "null") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }

            if(!getline(ss, token, ',')) break;
            if(token != "null") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
            


        }
        return root;
        
    }
};
