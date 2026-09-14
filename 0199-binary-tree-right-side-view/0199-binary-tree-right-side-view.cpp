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
    vector<int> rightSideView(TreeNode* root) {
        if (root==NULL) return {};
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        map<int, int>mp;

        while(!q.empty()){
            auto it = q.front(); q.pop();
            TreeNode* curr = it.first;
            int level = it.second;

            mp[level] = curr->val;
            if (curr->left){
                q.push({curr->left, level+1});
            }
            if (curr->right){
                q.push({curr->right, level+1});
            }
        }   

        vector<int>ans;
        for (auto it:mp){
            ans.push_back(it.second);
        }
        return ans;

    }
};