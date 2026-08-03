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
 TreeNode* build(vector<int>& preorder,
 int& preidx,int instart,int inend,unordered_map<int,int>& mp){
    
    if(instart > inend) return nullptr;

    int rootval = preorder[preidx];
    preidx++;

    TreeNode* root = new TreeNode(rootval);
    int divi = mp[rootval];

    root->left = build(preorder,preidx,instart,divi-1,mp);
    root->right = build(preorder,preidx,divi+1,inend,mp);
    return root;

 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n = inorder.size(),preindx = 0;
        for(int i =0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,preindx,0,n-1,mp);
        
    }
};
