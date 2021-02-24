#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {};
    TreeNode(int x, TreeNode* _left, TreeNode* _right):val(x), left(_left), right(_right){};
};
TreeNode *createTree(TreeNode *p){
    if (!p)
        return nullptr;
    TreeNode *root = new TreeNode(p->val);
    root->left = createTree(p->right);
    root->right = createTree(p->left);
    return root;
}
void Mirror(TreeNode *pRoot){
    // pRoot 翻转了
    pRoot = createTree(pRoot);
}
// void Mirror(TreeNode *pRoot){
//     if (!pRoot)
//         return;
//     TreeNode *temp = pRoot->left;
//     pRoot->left = pRoot->right;
//     pRoot->right = temp;
//     Mirror(pRoot->left);
//     Mirror(pRoot->right);
// }
int main(){
    TreeNode* p = new TreeNode(8, new TreeNode(7), new TreeNode(6));
    Mirror(p);  // p保持不变 有点类似形参
    return 0;
}