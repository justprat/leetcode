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
    int solve(TreeNode * root,int sum){

        if(root==NULL) return 0;

        if(root->val == sum && !root->left && !root->right) return 1e8;

        int left = solve(root->left,sum - root->val);
        int right = solve(root->right,sum - root->val);

        if(left == 1e8 || right == 1e8) return 1e8;

        return 1; 
    }


    bool hasPathSum(TreeNode* root, int targetSum) {

        return solve(root,targetSum) == 1e8 ? true : false;    
        
    }
};