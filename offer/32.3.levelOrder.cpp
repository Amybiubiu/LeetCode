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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 这里真是神奇，本来以为用 栈 或 堆 都差不多
        // 没想到用 栈 的话，偶然就很顺
        if(!root) return {};
        vector<vector<int>> res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        bool l2r = false;
        while(!s1.empty() || !s2.empty()){
            vector<int> item;
            if(l2r){
                // 偶数层
                while(!s2.empty()){
                    TreeNode* temp = s2.top();
                    item.push_back(temp->val);
                    s2.pop();
                    if(temp->right) s1.push(temp->right);
                    if(temp->left) s1.push(temp->left);
                }
            }else{
                // 奇数层
                while(!s1.empty()){
                    TreeNode* temp = s1.top();
                    item.push_back(temp->val);
                    s1.pop();
                    if(temp->left) s2.push(temp->left);
                    if(temp->right) s2.push(temp->right);
                }
            }
            l2r = !l2r;
            res.push_back(item);
        }
        return res;
    }
};