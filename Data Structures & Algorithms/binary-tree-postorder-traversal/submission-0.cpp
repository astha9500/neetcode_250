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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        vector<int>ans;
        if(root == nullptr) return ans;
        st1.push(root);

        while(!st1.empty()){
           TreeNode* n = st1.top();
           st1.pop();
           if(n->left != nullptr) st1.push(n->left);
           if(n->right != nullptr) st1.push(n->right);
           st2.push(n);
        }
       while(!st2.empty()){
        TreeNode* ne = st2.top();
        st2.pop();
        ans.push_back(ne->val);
       }
       return ans;
        
    }
};