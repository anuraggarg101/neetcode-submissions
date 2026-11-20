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
    int findVal(vector<int> &vec, int val, int start, int end) {
        int low = start;
        int high = end;
        while(low <= high) {
            int mid = (high + low)/2;
            if(vec[mid] == val) return mid;
            else if(vec[mid] < val) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    TreeNode* helper(vector<int> &preorder, unordered_map<int, int> &mp, vector<int> &inorder,int in_start, int in_end, int &pre_idx) {
        if(in_start > in_end) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_idx++]);
        int idx = mp[root->val];//findVal(inorder, root->val, in_start, in_end);
        root->left = helper(preorder, mp, inorder, in_start, idx - 1, pre_idx);
        root->right = helper(preorder, mp, inorder, idx + 1, in_end, pre_idx);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        unordered_map<int, int> mp{};
        for(int i=0;i<n;i++) {
            mp[inorder[i]] = i;
        }
        int pre_idx = 0;
        int in_start = 0;
        int in_end = n-1;
        return helper(preorder, mp, inorder, in_start, in_end, pre_idx);


    }
};
