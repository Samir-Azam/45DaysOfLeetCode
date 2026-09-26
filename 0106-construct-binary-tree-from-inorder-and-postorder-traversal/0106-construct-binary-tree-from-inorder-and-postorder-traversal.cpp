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
    TreeNode* helper(vector<int>& inorder, int ins, int ine, vector<int>& postorder, int ps, int pe, unordered_map<int, int>& inorder_map){


        if (ins>ine || ps>pe) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = inorder_map[root->val];
        int numsLeft = inRoot-ins;

        root->left = helper(inorder, ins, inRoot-1, postorder, ps, ps+numsLeft-1, inorder_map);
        root->right = helper(inorder, inRoot+1, ine, postorder, ps+numsLeft, pe-1, inorder_map);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()!=postorder.size()) return NULL;

        unordered_map<int, int>mp;

        for (int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};