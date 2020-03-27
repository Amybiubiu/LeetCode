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
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n){
            return helper(1,n);
        }else
            return vector<TreeNode*> {};
    }
    
    vector<TreeNode*> helper(int left, int right){
        vector<TreeNode*> res;
        if(right < left){
            res.push_back(NULL);
            return res;
        }
        
        for(int i=left; i <= right; i++){
            vector<TreeNode*> leftNodes = helper(left,i-1);
            vector<TreeNode*> rightNodes = helper(i+1,right);
            //对于最深层次的两个for循环是并没有循环，而只进行了一次，那这次for循环完了就有了一个leftNodes数组
            //转而调入跳入倒数第二层，进入该层次的时候才是进行两个for循环
            for(TreeNode* leftNode : leftNodes){
                for(TreeNode* rightNode : rightNodes){
                    TreeNode* temp = new TreeNode (i);
                    temp->left = leftNode;
                    temp->right = rightNode;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};