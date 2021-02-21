/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    bool compare(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if((!left && right) || (left && !right)) return false;
        if(left->val == right->val){
            return compare(left->left, right->right) && compare(left->right, right->left);
        }else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        // write code here
        if(!root) return true;
        return compare(root->left, root->right);
    }
};