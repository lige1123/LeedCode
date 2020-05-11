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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root->val == p ->val || root->val == q->val) {
            return root;
        }
        TreeNode *s = lowestCommonAncestor(root->left, p, q), *t = lowestCommonAncestor(root->right, p, q);
        if (s && t) return root;
        return s != NULL ? s : t;
        return NULL;
    }
};
