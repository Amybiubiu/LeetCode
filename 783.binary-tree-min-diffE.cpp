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
        int minDif = 100;
        int comp1 = -100;
        int comp2 = -100;
        
    int minDiffInBST(TreeNode* root) {
       
        
        return search(root);
    };
    int search(TreeNode* r){
        if(!r)
            return minDif;
        if(r->left){
            search(r->left);
        };
        comp1 = comp2;
        comp2 = r->val;
        minDif = min(minDif,comp2 - comp1);
        if(r->right){
            search(r->right);
        };
        return minDif;
    }
    
};
