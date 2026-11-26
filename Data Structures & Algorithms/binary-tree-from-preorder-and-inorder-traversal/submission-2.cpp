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
    unordered_map<int, int> inorderIndex{};

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &idx, int start, int end) {
        if(start > end) {
            return nullptr;
        }

        int root_val = preorder[idx++];
        TreeNode* node = new TreeNode(root_val);
        
        int mid = inorderIndex[root_val];
        node->left = helper(preorder, inorder, idx, start, mid - 1);
        node->right = helper(preorder, inorder, idx, mid + 1, end);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return nullptr;
        inorderIndex.clear();
        for(int i=0;i<n;i++) {
            inorderIndex[inorder[i]] = i;
        }
        int idx = 0;
        return helper(preorder, inorder, idx, 0, n-1);
    }
};
