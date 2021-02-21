/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>;
class Solution {
public:
    vector<int> preOrder;
    unordered_map<int, int> dic;
    TreeNode* reverse(int root, int left, int right){
        if(right < left) return nullptr;
        TreeNode* node = new TreeNode(preOrder[root]);
        int i = dic[preOrder[root]];
        node->left = reverse(root + 1, left, i - 1);
        node->right = reverse(root + i - left + 1, i + 1, right);
        return node;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        preOrder = pre;
        for(int i = 0; i < vin.size(); i++){
            dic[vin[i]] = i;
        }
        return reverse(0, 0, vin.size()-1);
    }
};