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
    
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        else
            return solve(root,0);
    }
    
    int solve(TreeNode* head,int res){
        if(!head)
            return res;
        else{
            int n1= solve(head->left,res+1);
            int n2= solve(head->right,res+1);
            if(n1>n2)
                return n1;
            else
                return n2;
        }
    }
};