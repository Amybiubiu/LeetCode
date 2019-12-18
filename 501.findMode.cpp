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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* preNode = NULL;
        int maxNum = 1;
        int curNum = 1;
        return inOrder(root,preNode,maxNum,curNum,res);
    }
    
    vector<int> inOrder(TreeNode* root,TreeNode*& preNode,int& maxNum,int& curNum,vector<int>& res){
        if(!root) return res;
        inOrder(root->left,preNode,maxNum,curNum,res);
        
        if(preNode){
             curNum = root->val == preNode->val ? curNum+1:1;
        }
       
        if(curNum == maxNum){
            res.push_back(root->val);
        };
        if(curNum > maxNum){
            res.clear();
            res.push_back(root->val);
            maxNum = curNum;
        };
        preNode = root;
        inOrder(root->right,preNode,maxNum,curNum,res);
        return res;
    }
    
};