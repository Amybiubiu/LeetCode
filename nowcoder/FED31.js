function functions(flag) {
    if (flag) {
      var getValue = function () { return 'a'; }
    } else {
      var getValue = function () { return 'b'; }
    }

    return getValue();
}
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
 class Solution {
  public:
      /**
       * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
       *
       * 
       * @param root TreeNode类 
       * @param failId int整型 
       * @param timeCost int整型vector 
       * @return int整型
       */
      int getPos(TreeNode* root, int failId){
          int pos = 0;
          // 二叉树的层次遍历
          queue<TreeNode*> q;
          q.push(root);
          while(!q.empty()){
              int size = q.size();
              while(size--){
                  TreeNode* temp = q.front();
                  q.pop();
                  pos++;
                  if(temp->val == failId) return pos;
                  if(temp->left) q.push(temp->left);
                  if(temp->right) q.push(temp->right);
              }
          }
      }
      int GetMinTimeCost(TreeNode* root, int failId, vector<int>& timeCost) {
          if(!root) return 0;
          // write code here
          int pos = getPos(root, failId);
          int res = 0;
          res += timeCost[pos];
          int end = 0;
          int i = 1;
          while(pos < end){
              end += 2^i;
              i++;
          }
          for(int i = pos; i < timeCost.size(); i++){
              int max = 0;
          }
      }
  };