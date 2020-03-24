/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int max(int a, int b) {
    return a > b ? a : b;
}


void search(struct TreeNode *root, int *i, int dp[][5]) {
    if (root == NULL) return ;
    if (root->left != NULL) {
        search(root->left, i, dp);
    }
    if (root->right != NULL) {
        search(root->right, i, dp);
    }
    if(root->left != NULL) {
        dp[*i][0] = max(dp[root->left->val][0], dp[root->left->val][1]);
    }
    if(root->right != NULL) {
        dp[*i][0] += max(dp[root->right->val][0], dp[root->right->val][1]);
    }
   // printf("%d\n", *i);
  //  printf("%d\n", dp[*i][1]);
    dp[(*i)][1] = root->val;
    if (root->right != NULL) {
        dp[*i][1] += (dp[root->right->val][0]);
    }
    if (root->left != NULL) {
        dp[*i][1] += dp[root->left->val][0];
    }
    root->val = (*i);
    (*i)++;
}




int rob(struct TreeNode* root){
    if (root == NULL) return 0;
    int dp[100005][5] = {0};
    int i = 0;
    search(root, &i, dp);
    return max(dp[i - 1][1], dp[i - 1][0]);
}
