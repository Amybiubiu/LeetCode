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
    TreeNode* pruneTree(TreeNode* root) {
        // 0
        if(!root) return nullptr;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        if(root->left) root->left = left = pruneTree(root->left);
        if(root->right) root->right = right = pruneTree(root->right);
        if(left || right){
            return root;
        }else{
            if(root->val == 1){
                return root;
            }else{
                return nullptr;
            }
        }
    }
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        // 0
        if(!root) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(!root->left && !root->right && root->val == 0){
            return nullptr;
        }
        return root;
    }
};