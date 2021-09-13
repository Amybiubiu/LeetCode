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
    int kthLargest(TreeNode* root, int k) {
        int count = 0;
        traverse(root, k, count);
        return res;
    }
    void traverse(TreeNode* p, int k, int& count){
        if(!p) return;
        if(p->right) traverse(p->right, k, count);
        if(++count == k) res = p->val;
        if(p->left) traverse(p->left, k, count);

        return;
    }
};