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
    TreeNode* solver(vector<int>& preorder, int &idx, int max){
        if (idx==preorder.size() || preorder[idx]>max) return NULL;
        

        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = solver(preorder, idx, root->val);
        root->right = solver(preorder, idx, max);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size()==0) return NULL;
        int val = 0;
        return solver(preorder, val, INT_MAX);
        
    }
};