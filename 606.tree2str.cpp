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
    string res;
    string tree2str(TreeNode* root) {
        if(!root) return "()";
        dfs(root);
        return res.substr(1, res.size()-2);
    }
    void dfs(TreeNode* root){
        res += "(";
        res += to_string(root->val);
        if(root->left){
            dfs(root->left);
        }else if(root->right){
            res += "()";
        }
        if(root->right){
            dfs(root->right);
        }
        res += ")";
    }
    // void dfs(TreeNode* root){
    //     if(!root){
    //         // res += "()";
    //         return;
    //     }
    //     res += to_string(root->val);
    //     if(!root->left && !root->right)
    //         return;
    //     res += "(";
    //     cout<<root->val;
    //     cout<<" left"<<endl;
    //     dfs(root->left); // 2
    //     // res += ")";
    //     if(root->right){
    //         // res += "(";
    //         dfs(root->right);
    //         // res += ")";
    //     }
    //     cout<<root->val;
    //     cout<<" right"<<endl;
    //     res += ")";
    // }
};
// 第一种写法，每个节点都是单独的一棵树；第二种错误的写法，每个叶子不被认为是一颗树。
// 第二种正确的复杂写法-》第一种简单的写法