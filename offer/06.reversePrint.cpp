/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> res;
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head) return res;
        reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};