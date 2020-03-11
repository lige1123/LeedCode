/*************************************************************************
	> File Name: Leetcode_206.cpp
	> Author: zhangze
	> Mail: zhangze_8_8sina.com
	> Created Time: Fri 28 Feb 2020 05:45:52 PM CST
 ************************************************************************/

#include<iostream>


/**
*  * Definition for singly-linked list.
*   * struct ListNode {
*    *     int val;
*     *     struct ListNode *next;
*      * };
*       */


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p, *q;
    p = head;
    head = NULL;
    while (p) {
        q = p->next;
        p->next = head;
        head = p;
        p = q;       
    }
    return head;
}

