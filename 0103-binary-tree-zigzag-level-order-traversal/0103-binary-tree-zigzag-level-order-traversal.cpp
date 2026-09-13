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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==NULL) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;

        q.push(root);

        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);
            for (int i=0;i<size;i++){
                TreeNode* topNode = q.front(); q.pop();
                int idx = leftToRight?i:size-1-i;
                temp[idx] = topNode->val;
                if (topNode->left) q.push(topNode->left);
                if (topNode->right) q.push(topNode->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(temp);
        }
        return ans;
    }
};