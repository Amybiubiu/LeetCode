/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 超时的先序遍历，之后再改。。。。
class Codec {
private:
    string chunk = "";
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // root -> nullptr $
        if(root == nullptr){
            chunk.push_back('$');
        }else{
            chunk.push_back(root->val);
            
            serialize(root->left);
            serialize(root->right);
        }
        return chunk;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        int i = 0;
        return preorder(data, i, data.size());
    }
    
    TreeNode* preorder(string data, int& i, int n){
        TreeNode* res;
        if(data[i] == '$'){
            res = nullptr;
            i++;
        }else{
            res = new TreeNode(data[i]);
            i++;
            if(i < n){
                res->left = preorder(data, i, n);
            }
            if(i < n){
                res->right = preorder(data, i, n);
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));