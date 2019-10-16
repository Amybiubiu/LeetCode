/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function(head) {
    if(head == null || head.next == null) return null;
    var slow = head;
    var fast = head;
    
    while(fast != null && fast.next != null){
        fast = fast.next.next;
        slow = slow.next;
        if(fast == slow){
            slow = head;
            while(fast != slow){
                fast = fast.next;
                slow = slow.next;
            }
            return fast;
            break;
        }   
    }
    return null;
};