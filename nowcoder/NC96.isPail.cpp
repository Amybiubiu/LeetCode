/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        vector<int> arr;
        ListNode* p = head;
        while(p){
            arr.push_back(p->val);
            p = p->next;
        }
        for(int i = 0, j= arr.size()-1; i < j; ++i, --j){
            if(arr[i] != arr[j])
                return false;
        }
        return true;
    }
};