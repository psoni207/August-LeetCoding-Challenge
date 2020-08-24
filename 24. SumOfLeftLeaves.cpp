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
    int res = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL){
            return res;
        }
        
        helperSolve(root->left, 1);
        helperSolve(root->right, 0);
        
        return res;
    }
    
    void helperSolve(TreeNode* root, bool isLeft){
        if(root == NULL ){
            return;
        }
        if(isLeft && !root->left && !root->right){
            res += root->val;
        }
        
        helperSolve(root->left, 1);
        helperSolve(root->right, 0);
    }
};