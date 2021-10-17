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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;
        while(!q.empty()){
            int s = q.size();
            deque<int> dq;
            for(int i = 0; i < s; i++){
                auto node = q.front();
                q.pop();
                if(l2r){
                    dq.push_back(node->val);
                }else{
                    dq.push_front(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            l2r = !l2r;
            res.push_back(vector<int>{dq.begin(), dq.end()});
        }
        return res;
    }
};