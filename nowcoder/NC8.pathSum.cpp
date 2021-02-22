/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> res;
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        // write code here
        vector<int> path;
        resolution(root, sum, path);
        return res;
    }
    void resolution(TreeNode* p, int sum, vector<int> path){
        // sum < 0 也继续递归 因为存在负数的数据
        if(!p){
            return;
        }else{
            path.push_back(p->val);
        }
        int dic = sum - p->val;
        if(dic == 0 && p->left == NULL && p->right == NULL)
            res.push_back(path);
        resolution(p->left, dic, path);
        resolution(p->right, dic, path);
    }
};
