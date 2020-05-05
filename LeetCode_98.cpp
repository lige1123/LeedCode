/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool isValid(TreeNode *root, int *num, int *flag) {
        if (root == NULL) return true;
        if (isValid(root->left, num, flag)) {
            if (*num < root->val || *flag == 0) {
                *num = root->val;
                *flag = 1;
                return isValid(root->right, num, flag);
            }
            return false;
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        int num = 0, flag = 0;
        return isValid(root, &num, &flag);
    }
};
