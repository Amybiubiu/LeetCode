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
    unordered_map<int, int> m;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // key index to inorder
        // m.resize(inorder.size());
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return helper(preorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, int index, int left, int right){
        if(right < left){
            return nullptr;
        }
        int root_value = preorder[index];
        TreeNode* tree = new TreeNode(root_value);
        // 第二个参数 前序遍历的root inedx 
        // 第三个参数 中序遍历的树的起点 第四参数 中序遍历的树的终点
        // 用中序遍历的起点终点是为了计算 root index，root index 也是 buildTree 的关键
        tree->left = helper(preorder, index + 1, left, m[root_value] - 1);
        // 一定是 m[root_value] - left + 1
        tree->right = helper(preorder, index + m[root_value] - left + 1, m[root_value] + 1, right);
        return tree;
    }
};