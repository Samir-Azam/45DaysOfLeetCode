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
    void preorderTraversal(TreeNode* root, int i,int level, map<int, map<int, multiset<int>>> &mp){
        if (root==NULL) return;
        mp[i][level].insert(root->val);
        preorderTraversal(root->left, i-1 ,level+1, mp);
        preorderTraversal(root->right, i+1, level+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        preorderTraversal(root, 0, 0, mp);
        vector<vector<int>>ans;
        
        for (auto it1: mp){
            vector<int>temp;
            for (auto it2: it1.second){
                temp.insert(temp.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};