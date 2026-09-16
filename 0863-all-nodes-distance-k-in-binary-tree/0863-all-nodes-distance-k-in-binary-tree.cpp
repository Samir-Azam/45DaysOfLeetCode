/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,map<TreeNode* ,TreeNode*>&mp){
        if (!root) return;
       queue<TreeNode* >q;
       q.push(root);
       while(!q.empty()){
        int size = q.size();
        for (int i = 0;i<size;i++){
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) {
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
        }
       }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* ,TreeNode*>parentPointer;
        parent(root,parentPointer);
        map<TreeNode* ,bool>freq;
        freq[target] = true;
        int i = 0;
        queue<TreeNode*>q;
        q.push(target);
        while (!q.empty()){
            if (i==k) break;
            int size = q.size();
            for (int i=0;i<size;i++){
                TreeNode* temp = q.front();q.pop();
                if (temp->left!= NULL and freq.find(temp->left)==freq.end()){
                freq[temp->left] = true;
                q.push(temp->left);
                }
                if (temp->right!= NULL and freq.find(temp->right)==freq.end()){
                    freq[temp->right] = true;
                    q.push(temp->right);
                }
                if (parentPointer.find(temp)!=parentPointer.end() and freq.find(parentPointer[temp])==freq.end()){
                    freq[parentPointer[temp]] = true;
                    q.push(parentPointer[temp]);
                }
            }
            i++;
        }
    vector<int>ans;
    while (!q.empty()){
        ans.push_back((q.front())->val);
        q.pop();

    }
    return ans;
    }
};