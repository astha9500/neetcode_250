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
int maxi = INT_MIN;
   int maxp(TreeNode* node){
    if(!node) return 0;

    int ls = max(0,maxp(node->left));
    int rs = max(0,maxp(node->right));

    maxi = max(maxi,node->val+ls+rs);

    return node->val+max(ls,rs);  
   }
    int maxPathSum(TreeNode* root) {
       
        maxp(root);
        return maxi;

    }
};
