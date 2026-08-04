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

class Codec {
public:

  string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(cur){
                ans += to_string(cur->val)+",";
                q.push(cur->left);
                q.push(cur->right);
            }
            else ans += "#,";
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.empty()) return nullptr;

       stringstream ss(data);
       string str;
       getline(ss,str,',');
       TreeNode* root = new TreeNode(stoi(str));
       queue<TreeNode*>q;
       q.push(root);

       while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        getline(ss,str,',');
        if(str != "#"){
            cur->left = new TreeNode(stoi(str));
            q.push(cur->left);
        }
        getline(ss,str,',');
        if(str != "#"){
            cur->right = new TreeNode(stoi(str));
            q.push(cur->right);
        }
       }
        return root;
    }
};

