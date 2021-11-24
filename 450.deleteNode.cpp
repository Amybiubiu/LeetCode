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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if(root == nullptr) return nullptr;
        if(root == nullptr) return nullptr;
        // if(root == nullptr) return nullptr;
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else if(root-> val > key){
            root->left = deleteNode(root->left, key);
        }else if(root->val == key){
            if(!root->right) return root->left;
            if(!root->left) return root->right;
            TreeNode* node = root->right;
            while(node->left){
                node = node->left;
            }
            node->left = root->left;
            root = root->right;
        }
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) 
//     {
//         if (root == nullptr)    return nullptr;
//         if (key > root->val)    root->right = deleteNode(root->right, key);     // 去右子树删除
//         else if (key < root->val)    root->left = deleteNode(root->left, key);  // 去左子树删除
//         else    // 当前节点就是要删除的节点
//         {
//             if (! root->left)   return root->right; // 情况1，欲删除节点无左子
//             if (! root->right)  return root->left;  // 情况2，欲删除节点无右子
//             TreeNode* node = root->right;           // 情况3，欲删除节点左右子都有 
//             while (node->left)          // 寻找欲删除节点右子树的最左节点
//                 node = node->left;
//             node->left = root->left;    // 将欲删除节点的左子树成为其右子树的最左节点的左子树
//             root = root->right;         // 欲删除节点的右子顶替其位置，节点被删除
//         }
//         return root;    
//     }
// };
