/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void Deep(struct TreeNode *root, int *deepth, int *result) {
    if (root == NULL) {
        return ;
    }
    int l_deepth = 0;
    Deep(root->left, &l_deepth, result);
    int r_deepth = 0;
    Deep(root->right, &r_deepth, result);
    if ((*result) < (l_deepth + r_deepth)) *result = (l_deepth + r_deepth);
    *deepth = (l_deepth > r_deepth ? l_deepth : r_deepth) + 1;
}


int diameterOfBinaryTree(struct TreeNode* root){
    int deepth = 0, result = 0;
    Deep(root, &deepth, &result);
    return result;
}
