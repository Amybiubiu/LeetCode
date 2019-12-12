/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        vector<Node*> Nodes;
        Nodes.push_back(root);
        while(!Nodes.empty()){
            Node* temp = Nodes.front();
           
            if(!temp) continue;
            res.push_back(temp->val);//这样会超时？
            
            Nodes.erase(Nodes.begin());
            //
            Nodes.insert(Nodes.begin(),temp->children.begin(),temp->children.end());
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<int> preorder(Node* root) {
//         vector<int> res;
//         vector<Node*> nodes; nodes.push_back(root);
//         Node* tmp;
//         while(!nodes.empty()){
//             tmp = nodes.front(); nodes.erase(nodes.begin());
//             if(tmp == NULL) continue;
//             res.push_back(tmp->val);
//             nodes.insert(nodes.begin(), tmp->children.begin(), tmp->children.end());
//         }
//         return res;
//     }
// };


