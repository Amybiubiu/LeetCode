/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        // 添加 next
        Node* p = head;
        while(p){
            Node* new_node = new Node(p->val);
            Node* temp = p->next;
            p->next = new_node;
            new_node->next = temp;
            
            p = temp;
        }
        // 添加 radom
        p = head;
        while(p){
            if(p->random){
                // Random pointer of node with label 13 points to a node from the original list.
                // p->next->random = p->random
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        // 分离
        p = head;
        Node* clonedHead = head->next;
        Node* pClone = clonedHead;
        while(p){
            // cout<<p->val<<endl;
            // if(pClone->random)
            //         cout<<"random"<<pClone->random->val<<endl;
            p->next = pClone->next;
            p = p->next;
            if(p){
                // cout<<pClone->val<<endl;
                // if(pClone->random)
                //     cout<<"random"<<pClone->random->val<<endl;
                pClone->next = p->next;
                pClone = pClone->next;
            }

        }
        
        return clonedHead;
    }
};