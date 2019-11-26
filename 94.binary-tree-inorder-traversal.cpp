
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || s.size()){
            while(rt){
                s.push(rt);
                rt = rt->left;
            };
            rt = s.top();
            s.pop();
            v.push_back(rt->val);
            rt = rt->right;
        }
        return v;
    }
};