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
    bool helper(TreeNode* root, int min_val, int max_val) {
        if(!root) return true;

        int curr = root->val;
        if(curr >= max_val or curr <= min_val) return false;

        bool left = helper(root->left, min_val, curr);
        bool right = helper(root->right, curr, max_val);

        return left and right;        
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};
