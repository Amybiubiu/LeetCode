/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return nullptr;
        if(!root->left && !root->right){
            return root;
        }
        TreeNode* temp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(temp);
        return root;
    }
};