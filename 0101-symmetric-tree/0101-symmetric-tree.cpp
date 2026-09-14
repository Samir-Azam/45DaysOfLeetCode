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
public:
    bool helper(TreeNode* p, TreeNode* q){
        if (!p || !q) return p==q;

        if (p->val!=q->val) return false;
        if (helper(p->left, q->right)==false) return false;
        if (helper(p->right, q->left)==false) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};