/*************************************************************************
> File Name: Leetcode_142.cpp
> Author: zhangze
> Mail: zhangze_8_8sina.com
> Created Time: Wed 26 Feb 2020 12:23:36 AM CST
************************************************************************/

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) return NULL;
    struct ListNode *p = head, *q = head;
    do {
        p = p->next;
        q = q->next;
        if (p == NULL || q == NULL || q->next == NULL) return NULL;
        q = q->next;
    } while (p != q);
    int cnt = 0;
    do {
        cnt++;
        p = p->next;
    } while(p != q);
    p = head, q = head;
    while (cnt--) p = p->next;
    while (p != q) p = p->next, q = q->next;
    return p;
}



