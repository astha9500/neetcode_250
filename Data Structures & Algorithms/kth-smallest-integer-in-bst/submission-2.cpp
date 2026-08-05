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
int ans = -1;
int cnt =0;

void recur(TreeNode* root,int k){
    if(!root) return;

    recur(root->left,k);

    cnt++;
    if(cnt == k) {
        ans = root->val;
    return;
    }

    recur(root->right,k);

}
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        recur(root,k);
        return ans;
        
    }
};
