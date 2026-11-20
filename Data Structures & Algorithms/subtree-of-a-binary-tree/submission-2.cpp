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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if(!a and !b) return true;
        if(!a or !b) return false;
        return (a->val == b->val) and isSameTree(a->left, b->left) and isSameTree(a->right, b->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot) return true;
        if(!root) return false;
        if(!subRoot) return false;
        
        
        if(root->val == subRoot->val) {
            bool res = isSameTree(root, subRoot);
            if(res) return true;
        }
        
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
        
    }
};
