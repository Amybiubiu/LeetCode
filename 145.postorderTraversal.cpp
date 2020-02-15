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
    vector<int> res;
    //recursive program
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return res;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }
};

// 迭代

// 前序
stack<TreeNode*> mystack;
        TreeNode* curr = root;
        vector<int> ans;
        while(curr || !mystack.empty())
        {
            while(curr)
            {
                ans.push_back(curr->val);
                mystack.push(curr);
                curr = curr->left;
            }
            curr = mystack.top();
            mystack.pop();
            curr = curr->right;
        }
        return ans;
// 中序
vector<int> ans;
        stack<TreeNode*> mystack;
        TreeNode* curr = root;
        
        while(curr || !mystack.empty())
        {
            while(curr)
            {
                mystack.push(curr);
                curr = curr->left;
            }
            curr = mystack.top();
            mystack.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
// 后序
 stack<TreeNode*> mystack;
        vector<int> ans;
        TreeNode* curr = root;
        TreeNode* pre = NULL;
        
        while(curr || !mystack.empty())
        {
            while(curr)
            {
                mystack.push(curr);
                curr = curr->left;
            }
            curr = mystack.top();
            
            //若右节点已经访问过或者没有右节点  则输出该节点值
            if(!curr->right || pre == curr->right){
                mystack.pop();
                ans.push_back(curr->val);    
                pre = curr;
                curr = NULL;
            }else{
                curr = curr->right;
                pre = NULL;
            }
        }
        return ans;