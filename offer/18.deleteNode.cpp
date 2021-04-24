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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) return head->next;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur->val != val){
            prev = cur;
            cur = cur->next;
        }
        if(!cur) prev->next = nullptr;
        prev->next = cur->next;
        return head;
    }
};