/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    Node* pre;
    Node* head;
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    
    void dfs(Node* cur){
        // 把一个链看成一个单位处理，而不是一棵树。
        if(!cur) return;
        dfs(cur->left);
        // 节点连接的操作都放在当前遍历的节点中
        if(!pre){
            head = cur;
        }else{
            pre->right = cur;
        }
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};