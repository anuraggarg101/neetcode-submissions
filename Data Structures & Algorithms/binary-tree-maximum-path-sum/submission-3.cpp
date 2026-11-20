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
    int max_val = INT_MIN;
    int helper(TreeNode* root) {
        if(!root) return 0;

        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));

        int curr = root->val + left + right;
        max_val = max(max_val, curr);
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        max_val = INT_MIN;
        helper(root);
        return max_val;
    }
};
