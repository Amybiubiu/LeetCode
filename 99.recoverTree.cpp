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
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pre = nullptr;

        // 非迭代的中序遍历
        stack<TreeNode*> st;

        while(!st.empty() || root != nullptr ){
            while(root){
                st.push(root);
                root = root->left;
                // root->left 指针不移动能不超时吗，检查一下就能知道的，还去看答案
            }

            root = st.top();
            st.pop();

            if(pre && root->val < pre->val){
                x = root;
                if(y == nullptr){
                    y = pre;
                }else
                    break;
            }

            pre = root;
            root = root->right;
        }

        swap(x->val, y->val);
    }
};