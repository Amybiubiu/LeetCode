/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        int last = head->val;
        ListNode* p = head;
        ListNode* pre = head;
        while(p){
            if(p->val != last){
                 last = p->val;
                 pre = p;
            }  
            else{
                pre->next = p->next;
            }          
            p = p->next;
        }
        return head;
    }
};