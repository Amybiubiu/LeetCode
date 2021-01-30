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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(treeDepth(root->left) - treeDepth(root->right)) < 2){
            return isBalanced(root->left) && isBalanced(root->right);
        }else
            return false;
    }
    int treeDepth(TreeNode* tree){
        if(!tree)  return 0;
        return max(treeDepth(tree->left), treeDepth(tree->right)) + 1;
    }
};
