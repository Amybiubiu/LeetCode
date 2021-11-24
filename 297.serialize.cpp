/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string res = "";
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "$";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + "," + right ;
    }
    TreeNode* dfs(vector<string> data, int& i, int n){
        TreeNode* res;
        if(data[i] == "$"){
            res = nullptr;
            i++;
        }else{
            res = new TreeNode(atoi(data[i].c_str()));
            i++;
            if(i < n){
                res->left = dfs(data, i, n);
            }
            if(i < n){
                res->right = dfs(data, i, n);
            }
        }
        return res;
    }
    // Decodes your encoded data to tree.
    vector<string> format(string data){
        vector<string> res;
        int i = 0, n = data.size();
        while(i < n){
            string temp = "";
            while(i < n && data[i] != ','){
                temp += data[i++];
            }
            if(temp != ""){
                // cout<<temp<<endl;
                res.push_back(temp);
            }
            i++;
        }
        return res;
    }
    TreeNode* deserialize(string data) {
        // cout<<"data"<<data<<endl;
        int i = 0;
        vector<string> formatData = format(data);
        return dfs(formatData, i, formatData.size());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));