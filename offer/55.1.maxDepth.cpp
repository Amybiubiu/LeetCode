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
private:
    int res = 0;
public:
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode* root, int depth){
        if(!root){
            res = max(res, depth);
            return;
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
};