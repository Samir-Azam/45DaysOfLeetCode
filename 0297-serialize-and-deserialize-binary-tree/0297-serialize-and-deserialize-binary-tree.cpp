/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==NULL) return "";
        queue<TreeNode*>q;
        string data = "";
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if (temp==NULL){
                data.append("#,");
            }
            else{
                data.append(to_string(temp->val)+',');
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="") return NULL;
        stringstream s(data);
        string varr = "";
        getline(s,varr,',');
        TreeNode* root = new TreeNode(stoi(varr));
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            getline(s,varr,',');
            if (varr!="#"){
                temp->left = new TreeNode(stoi(varr));
                q.push(temp->left);
            }
            else{
                temp->left = NULL;
            }
            getline(s,varr,',');
            if (varr!="#"){
                temp->right = new TreeNode(stoi(varr));
                q.push(temp->right);
            }
            else{
                temp->right = NULL;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));