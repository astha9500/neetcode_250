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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int cnt = 0;
        
        TreeNode* cur = root;
        while(cur){

            if(cur->left == nullptr){
                cnt++;
                 if(cnt == k) return cur->val; 
                 cur = cur->right;
            }
            else {
             TreeNode* prev = cur->left;
             while(prev->right && prev->right != cur) prev = prev->right;

            if(prev->right == nullptr){
             prev->right = cur;
             cur = cur->left;
            }
            else{
                 prev->right = nullptr;
                 cnt++;
                  if(cnt == k) return cur->val; 
                 cur = cur->right;
              }
            }

        }
            
        return 0;
        
    }
};
