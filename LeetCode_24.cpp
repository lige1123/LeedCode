
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = &(ret);
    q = p->next;
    while (q && q->next) {
        p->next = q->next;
        q->next = q->next->next;
        p->next->next = q;
        p = q;
        q = p->next;

    }
    return ret.next;

}


