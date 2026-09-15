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
    int widthOfBinaryTree(TreeNode* root) {
        // Logic is to give indexing to the nodes and once it is given for each level calculate last-first+1 that will be the maximum width
        if (root==NULL) return 0;
        queue<pair<TreeNode* , long long>>q;
        q.push({root, 0});
        int ans = INT_MIN;
        while(!q.empty()){
            auto it = q.front();
            int size = q.size();
            int min = it.second;
            int last = min;
            for (int i=1;i<=size;i++){
                auto curr = q.front(); q.pop();
                TreeNode* node = curr.first;
                int idx = curr.second-min; //Normalization
                last = curr.second;
                if (node->left){
                    q.push({node->left, 2LL*idx+1});
                }
                if (node->right){
                    q.push({node->right, 2LL*idx+2});
                }
            }
            ans = max(ans, last-min+1);

        }
        return ans;
    }
};