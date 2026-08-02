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
bool same(TreeNode* root,TreeNode* subroot){
      if(!root && !subroot) return true;

      if(root && subroot && root->val == subroot->val){
        return same(root->left,subroot->left) && 
              same(root->right,subroot->right);
      }
      return false;
}

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
              if(!subRoot) return true;
              if(!root) return false;

              if(same(root,subRoot)){
                return true;
              }
             
            return isSubtree(root->left,subRoot) ||
             isSubtree(root->right,subRoot);
        
    }
};
