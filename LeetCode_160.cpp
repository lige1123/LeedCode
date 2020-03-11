/*************************************************************************
> File Name: Leetcode_160.cpp
> Author: zhangze
> Mail: zhangze_8_8sina.com
> Created Time: Wed 26 Feb 2020 12:51:33 AM CST
************************************************************************/


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    while (p != q) {
        p = p ? p->next : headA;
        q = q ? q->next : headB;

    }
    return p;
}


