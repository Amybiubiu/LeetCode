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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool result = false;
        if(A && B){
            if(A->val == B->val){
                result = doesTree1HasTree2(A, B);
            }
            if(!result)
                result = isSubStructure(A->left, B);
            if(!result)
                result = isSubStructure(A->right, B);
        }
        return result;
    }
    
    bool doesTree1HasTree2(TreeNode* p1, TreeNode* p2){
        if(!p2)  return true;
        if(!p1)  return false;
        
        if(p1->val != p2->val)  return false;
        
        return doesTree1HasTree2(p1->left, p2->left) 
            && doesTree1HasTree2(p1->right, p2->right);
    }
};