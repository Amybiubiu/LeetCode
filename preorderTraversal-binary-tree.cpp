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
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> v;
//         TreeNode* rt = root;
//         if(rt==NULL)
//             return v;
//         v.push_back(rt->val);
//         preorderTraversal(rt->left);
//         preorderTraversal(rt->right);
//     }
// };
// solution.cpp: In member function preorderTraversal
// Line 19: Char 26: error: control reaches end of non-void function [-Werror=return-type]
//          preorderTraversal(rt->right);
//          ~~~~~~~~~~~~~~~~~^~~~~~~~~~~
// cc1plus: some warnings being treated as errors

class Solution {
public:
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) {
        pre_travel(root);
        return ret;
    }
    void pre_travel(TreeNode* root)
    {
        if(root)//当前结点非空
        {
            ret.push_back(root->val);//访问根节点
            pre_travel(root->left);//递归左子树
            pre_travel(root->right);//递归右子树
        }
    }
};
