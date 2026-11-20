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
    bool is_found = false;
    int res = 0;

    void inorder(TreeNode* root, int &cnt, int k) {
        if(!root or is_found) return;

        inorder(root->left,cnt, k);
        cnt++;
        if(cnt == k) {
            is_found = true;
            res = root->val;
        }
        inorder(root->right, cnt, k);
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        is_found = false;
        res = 0;
        int cnt = 0;
        inorder(root, cnt, k);
        return  res;
    }
};
