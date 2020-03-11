
int list_length(struct ListNode* head) {
    struct ListNode *p  = head;
    int n = 0;
    while (p) {
        p = p->next;
        n++;
    }
    return n;
}

struct ListNode* revese(struct ListNode *head, int n) {
    struct ListNode ret, *p = head, *q;
    while (n--) p = p->next;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}


bool isPalindrome(struct ListNode* head){
    int len = list_length(head);
    struct ListNode *p = head, *q  = revese(head, (len + 1) / 2);
    while (q) {
        if (p->val != q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}








