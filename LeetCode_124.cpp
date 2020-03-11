/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Findmax(struct TreeNode *root, int *sum, int *result) {
    if (root == NULL) return ;
    int l_sum = 0, r_sum = 0;
    Findmax(root->left, &l_sum, result);
    Findmax(root->right, &r_sum, result);
    l_sum = l_sum > 0 ? l_sum : 0;
    r_sum = r_sum > 0 ? r_sum : 0;
    if (*result < (l_sum + r_sum + root->val)) *result = (l_sum + r_sum + root->val);
    *sum = (l_sum > r_sum ? l_sum : r_sum) + root->val;
    return ;
}

int maxPathSum(struct TreeNode* root){
    int num = 0, result = -200000;
    Findmax(root, &num, &result);
    return result;
}
