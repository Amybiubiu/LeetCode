/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* g = dummyNode;
        ListNode* p = head;
        for(int i = 0; i < left - 1; i++){
            g = g->next;
            p = p->next;
        }

        for(int i = 0; i < right - left; i++){
            ListNode* removed = p->next;
            p->next = p->next->next;
            
            removed->next = g->next;
            g->next = removed;
        }
        return dummyNode->next;
    }
};