/*************************************************************************
> File Name: 101.cpp
> Author: zhangze
> Mail: zhangze_8_8@sina.com
> Created Time: Sat 29 Feb 2020 02:57:39 PM CST
************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

/**
*Definition for a binary tree node.
*struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


bool isSame(struct TreeNode *l, struct TreeNode *r) {
    if (!l&& !r) return true;
    if (!l|| !r) return false;
    if (l->val - r->val) return false;
    return isSame(l->left, r->right) && isSame(l->right, r->left);
}


bool isSymmetric(struct TreeNode* root){
    return isSame(root, root);
}




