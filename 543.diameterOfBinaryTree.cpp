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
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res-1;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left_l = dfs(root->left);
        int right_l = dfs(root->right);

        res = max(res, left_l + right_l + 1);
        return max(left_l, right_l) + 1;
    }
};