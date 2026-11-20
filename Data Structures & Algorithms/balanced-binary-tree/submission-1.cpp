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
    bool is_balanced = true;
    int helper(TreeNode* root) {
        // if(!is_balanced) return 0;

        if(!root) return 0;

        int lh = helper(root->left);
        int rh = helper(root->right);

        is_balanced &= (abs(lh-rh) <= 1);

        return 1 + max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        is_balanced = true;
        helper(root);
        return is_balanced;
    }
};
