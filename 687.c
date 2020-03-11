/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void FindLenth(struct TreeNode *root, int *val_result, int *result) {
    if (root == NULL) return ;
    int l_result = 0, r_result = 0;
    FindLenth(root->left, &l_result, result);
    FindLenth(root->right, &r_result, result);
    if (root->left && root->val == root->left->val) *val_result = l_result + 1;
    if (root->right && root->val == root->right->val) {
        *val_result = *val_result > (r_result + 1) ? *val_result : (r_result + 1);
        if (root->left && root->right && root->left->val == root->right->val && *result < (l_result + r_result + 2)) {
            *result = (l_result + r_result + 2);
        }
    }
    *result = (*result) > (*val_result) ? (*result) : (*val_result);
}



int longestUnivaluePath(struct TreeNode* root){
    int val_result = 0, result = 0;
    FindLenth(root, &val_result, &result);
    return result;
}
