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

        string str = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if (front==NULL) str.append("#,");
            else{
                str.append(to_string(front->val)+',');
                q.push(front->left);
                q.push(front->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();

            // for left child
            getline(s, str, ',');
            if (str=="#"){
                node->left = NULL;
            }else{
                TreeNode* leftChild = new TreeNode(stoi(str));
                q.push(leftChild);
                node->left = leftChild;
            }

            // for right child
            getline(s, str, ',');
            if (str=="#"){
                node->right = NULL;
            }else{
                TreeNode* rightChild = new TreeNode(stoi(str));
                q.push(rightChild);
                node->right = rightChild;
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));