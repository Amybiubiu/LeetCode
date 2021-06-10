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
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return {};
        vector<int> path;
        dfs(root, path, target);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& path, int target){
        path.push_back(root->val);
        target -= root->val;
        
        if(!root->left && !root->right){
            if(!target) res.push_back(path);
            return;
        }
        if(root->left) {
            dfs(root->left, path, target);
            path.pop_back();
        }
        if(root->right){
            dfs(root->right, path, target);
            path.pop_back();
        }
        return;
    }
};