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
    int solver(TreeNode* root, int &ans){
        if (root==NULL) return 0;

        int leftSum = max(0, solver(root->left, ans));
        int rightSum = max(0, solver(root->right, ans));

        ans = max(ans, root->val+leftSum+rightSum);
        return max(leftSum,rightSum)+root->val;
    }
public:

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solver(root, ans);
        return ans;
    }
};