var hasCycle = function(head) {
    if(head==null || head.next==null) return false;
    var slow = head;
    var fast = head.next;
    while(fast!=null && fast.next !=null){
        if(fast.val == slow.val)
            return true;
        fast = fast.next.next;
        slow = slow.next;
    }
    return false;
};

