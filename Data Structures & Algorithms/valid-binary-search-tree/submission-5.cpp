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
    bool helper(TreeNode* node, int max_allowed, int min_allowed) {
        if(!node) return true;
        if(node->val >= max_allowed or node->val <= min_allowed) {
            return false;
        }
        return helper(node->left, node->val, min_allowed) and helper(node->right, max_allowed, node->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MAX, INT_MIN);
    }
};
