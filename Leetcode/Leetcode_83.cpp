
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head, *q;
    while (p && p->next) {
        if (p->val - p->next->val) {
            p = p->next;
        } else {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    return head;
}



