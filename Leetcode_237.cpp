/*************************************************************************
	> File Name: Leetcode_237.cpp
	> Author: zhangze
	> Mail: zhangze_8_8sina.com
	> Created Time: Fri 28 Feb 2020 05:40:26 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


/*
*  * Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
*};
*/


void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}





