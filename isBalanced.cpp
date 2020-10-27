/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL) return true;
//         int left = dfs(root->left);
//         int right = dfs(root->right);
//         if(abs(left - right) > 1)
//             return false;
//         else
//             return true;
//     }
    
//     int dfs(TreeNode* node){
//         if(node == NULL)
//             return 0;
//         return max(dfs(node->left),dfs(node->right)) + 1;
//     }
// };
// [1,2,2,3,null,null,3,4,null,null,4] 202/227
class Solution {
public:
    int depth(TreeNode* root)//计算以root为根节点的子树的最大深度
    {
        if(root==NULL)  return 0;
        int left=depth(root->left);
        int right=depth(root->right);
        
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)  return true;
        
        if(abs(depth(root->left) - depth(root->right)) < 2)//如果根节点的左右子树高度差小于2
            return isBalanced(root->left) && isBalanced(root->right);//继续递归判断左孩子右孩子
        return false;
    }
};
