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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        if(targetSum == root->val && !root->left && !root->right){
            return true;
        }
        bool left = false, right = false;
        if(root->left) left = hasPathSum(root->left, targetSum - root->val);
        if(root->right) right = hasPathSum(root->right, targetSum - root->val);
        return left || right;
    }
};

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }

    bool helper(TreeNode* root, int targetSum, int pathSum){
        if(!root) return false;
        if(!root->left && !root->right){
            return targetSum == (pathSum + root->val);
        }else if(root->left && root->right){
            return helper(root->left, targetSum, pathSum + root->val) || helper(root->right, targetSum, pathSum + root->val);
        }else if(root->left){
            return helper(root->left, targetSum, pathSum + root->val);
        }else if(root->right){
            return helper(root->right, targetSum, pathSum + root->val);
        }
        return false;
    }
};