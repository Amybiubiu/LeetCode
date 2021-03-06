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
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return 0;
        rangeSumBST(root->left, L, R);  //只有 L < root->value 时候进入递归啊，这样写很多余
        if(root->val >= L && root->val <= R)
            sum += root->val;
        rangeSumBST(root->right, L, R);
        return sum;
    }
};