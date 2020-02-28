


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = q =  &ret;
    while (n--) q = q->next;
    q = q->next;
    while (q) {
        p = p->next;
        q = q->next;

    }
    p->next = p->next->next;
    free(q);
    return ret.next;

}


