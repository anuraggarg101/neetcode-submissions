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

class Solution {
private:    
    int dfs(TreeNode* node, int maxSoFar) {
        if(!node) return 0;

        bool is_good_node = (node->val >= maxSoFar);
        maxSoFar = max(maxSoFar, node->val);

        int left = dfs(node->left, maxSoFar);
        int right = dfs(node->right, maxSoFar);
        
        return left + right + static_cast<int>(is_good_node);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, INT_MIN);
    }
};
