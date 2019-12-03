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
    bool flag = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
         compare(p,q);
        return flag;
    }
    void compare(TreeNode* m,TreeNode* n){
        
        if(m && n){
            if(m->val != n->val){
                flag = false;
            }else{
                 compare(m->left,n->left);
                 compare(m->right,n->right);
            }
       }else if(!m && !n){
            
        }else
            flag = false;
    }
};