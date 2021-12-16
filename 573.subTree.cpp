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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        return compare(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool compare(TreeNode* tree1, TreeNode* tree2){
        if(!tree2 && !tree1) return true;
        if(tree1 && tree2 && tree1->val == tree2->val){
            return compare(tree1->left, tree2->left)&&compare(tree1->right, tree2->right);
        }else{
            return false;
        }
    }
    // 关于为什么一个 递归函数 不能解题 的原因
    // 在 subTree 中要 先序遍历 返回 res
    // 而在 compare 中一旦当前 != 就 返回 false
    // 两者的递归逻辑不一样

    // offer 26 similar
};