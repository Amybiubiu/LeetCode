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
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
    }
    bool isBST(TreeNode* root,long left,long right){
        if(!root) return true;
        if(root->val <= left) return false;
        if( root->val >= right) return false;
        return isBST(root->left, left ,root->val)&&isBST(root->right,root->val,right );
    }
    //   bool isValidBST(TreeNode* root) {
    //     return isBST(root,NULL,NULL);
    // }
    // bool isBST(TreeNode* root,int left,int right){
    //     if(!root) return true;
    //     if(left && root->val <= left) return false;
    //     if(right && root->val >= right) return false;
    //     return isBST(root->left, left ,root->val)&&isBST(root->right,root->val,right );
// [0,null,-1]
//我的天？我是个憨批，left 为 0 与 为 null 判断真假的时候情况一致，你如何去区分是哪种情况的导致的真和假。
//#define NULL    ((void *)0) 
// 有时间可以看看 null和nullprt
//还有记得考虑INT_MAX和INT_MIN的情况。
};

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
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)){
            return false;
        }
        if(root->val <= pre){
            return false;
        }
        pre = root->val;
        return isValidBST(root->right);
    }
};
