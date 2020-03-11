/*************************************************************************
> File Name: 107.cpp
> Author: zhangze
> Mail: zhangze_8_8@sina.com
> Created Time: Sat 29 Feb 2020 04:32:32 PM CST
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
*  * Definition for a binary tree node.
*   * struct TreeNode {
*    *     int val;
*     *     struct TreeNode *left;
*      *     struct TreeNode *right;
*       * };
*        */


/**
*  * Return an array of arrays of size *returnSize.
*   * The sizes of the arrays are returned as *returnColumnSizes array.
*    * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*     */

int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

void getCnt(struct TreeNode *root, int k, int *cnt) {
    if (root == NULL) return ;
    cnt[k]++;
    getCnt(root->left, k - 1, cnt);
    getCnt(root->right, k - 1, cnt);
}


void getResult(struct TreeNode * root, int k, int *cnt, int **ret) {
    if (root == NULL) return ;
    ret[k][cnt[k]++] = root->val;
    getResult(root->left, k - 1, cnt, ret);
    getResult(root->right, k - 1, cnt, ret);
}



int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int n = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * n);
    int *cnt = (int *)calloc(n, sizeof(int));
    getCnt(root, n - 1, cnt);
    for (int i = 0; i < n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;
    }
    getResult(root, n - 1, cnt, ret);
    *returnColumnSizes = cnt;
    *returnSize = n;
    return ret;
}

