/*************************************************************************
	> File Name: LeetCode_257.cpp
	> Author: zhangze
	> Mail: zhangze_8_8sina.com
	> Created Time: Mon 02 Mar 2020 04:08:30 PM CST
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getNum(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getNum(root->left) + getNum(root->right);
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if (root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    if (root->left == NULL && root->right == NULL ) {
        ret[k] = strdup(buff);
        return 1;
    }
    len += sprintf(buff + len, "->");
    int cnt = getResult(root->left, len, k, ret, buff);
    cnt += getResult(root->right, len, k + cnt, ret, buff);
    return cnt;
}


char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int n = getNum(root);
    char **Paths = (char **)calloc(n, sizeof(char *));
    char *str = (char *)calloc(1000 * n, sizeof(char));
    getResult(root, 0, 0, Paths, str);
    *returnSize = n;
    return Paths;
}
