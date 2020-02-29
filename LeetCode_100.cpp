/*************************************************************************
> File Name: LeetCode_100.cpp
> Author: zhangze
> Mail: zhangze_8_8sina.com
> Created Time: Sat 29 Feb 2020 02:40:54 PM CST
************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
using namespace std;





/**
*Definition for a binary tree node.
*     struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
*};
*/


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val - q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
}


