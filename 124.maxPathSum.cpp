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
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
    
        int left = dfs(root->left);
        int right = dfs(root->right);

        // 这里是拐弯的方式 好灵活
        int innerSum = root->val + left + right;
        res = max(res, innerSum);

        int outerSum = root->val + max(left, right);
        return max(outerSum, 0);
    }
};