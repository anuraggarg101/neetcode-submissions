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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        if(!p or !q) return false;
        return (p->val == q->val) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) {
            return true;
        }
        if(!root and subRoot) {
            return false;
        }

        bool res = false;
        if(root->val == subRoot->val) {
            res = isSameTree(root, subRoot);
        }

        if(!res) {
            res = isSubtree(root->left, subRoot);
        }
        if(!res) {
            res = isSubtree(root->right, subRoot);
        }
        return res;
    }
};
