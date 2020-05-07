/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isSubtree_1(TreeNode* s, TreeNode* t) {
        if (t == NULL && s == NULL) return true;
        else if (t == NULL || s == NULL) return false;
        else { 
            if ((s->val == t->val) && (isSubtree_1(s->left, t->left) && isSubtree_1(t->right, s->right))) {
                return true;
            }
            return false;
        }
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == NULL && s == NULL) return true;
        else if (t == NULL || s == NULL) return false;
        else { 
            if ((s->val == t->val) && (isSubtree_1(s->left, t->left) && isSubtree_1(t->right, s->right))) {
                return true;
            }
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};
