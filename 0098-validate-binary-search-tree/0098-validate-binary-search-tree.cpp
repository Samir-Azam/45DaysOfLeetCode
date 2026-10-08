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
    bool solver(TreeNode* root, long minr, long maxr){
        if (root==NULL) return true;
        if (long(root->val)<=minr || long(root->val)>=maxr) return false;
        return solver(root->left, minr, root->val) && solver(root->right, root->val, maxr);
    }
    bool isValidBST(TreeNode* root) {
        return solver(root, LONG_MIN, LONG_MAX);
    }
};