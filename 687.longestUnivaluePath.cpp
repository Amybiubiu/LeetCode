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
    int res = 0;
    int longestUnivaluePath(TreeNode* root) {
        resolution(root);
        return res;
    }
     //以某个节点为根节点的最长同值路径
    int resolution(TreeNode* root){
        if(!root) return 0;
        int leftLen = resolution(root->left);
        int rightLen = resolution(root->right);
        leftLen = (root->left && root->left->val == root->val)?leftLen+1:0;
        rightLen = (root->right && root->right->val == root->val)?rightLen+1:0;
        res = max(res,leftLen+rightLen);
        return max(leftLen,rightLen);
    }
};