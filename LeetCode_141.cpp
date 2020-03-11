/*************************************************************************
> File Name: Leetcode_141.cpp
> Author: zhangze
> Mail: zhangze_8_8@sina.com
> Created Time: Wed 26 Feb 2020 12:21:22 AM CST
************************************************************************/

/*
Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
*/

bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;
    struct ListNode *p = head, *q = head->next;
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
        if (p == q) return true;

    }
    return false;
}


