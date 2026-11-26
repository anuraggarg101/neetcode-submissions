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
    int ans = INT_MIN;
    int maxGain(TreeNode* root) {
        if(!root) return 0;

        int leftGain = max(0, maxGain(root->left));
        int rightGain = max(0, maxGain(root->right));

        int curr_sum = root->val + leftGain + rightGain;
        ans = max(ans, curr_sum);
        return root->val + max(leftGain, rightGain);
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxGain(root);
        return ans;
    }
};
