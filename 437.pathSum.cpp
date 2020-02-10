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
    int res = 0;
    int pathSum(TreeNode* root, int sum) {
        // vector<int> str;
        resolution(root,sum,new int[1000],0);
        return res;
    }
    //以该节点为终点的和为sum的路径条数,注意储存路径的方式
    void resolution(TreeNode* root,int sum,int* str,int p){
        if(!root) return ;
        str[p] = root->val;
        resolution(root->left,sum,str,p+1);
        resolution(root->right,sum,str,p+1);
        int temp = 0;
        for(int i = p;i>= 0;i--){
            temp += str[i];
            if(temp == sum)
                res++;
        }
        return ;
    }
    
};

