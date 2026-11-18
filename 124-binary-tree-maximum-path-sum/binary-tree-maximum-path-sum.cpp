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
    int solve(TreeNode *root,int &maxAns){

        if(root == NULL){
            return 0;
        }

        int left = solve(root->left,maxAns);
        int right = solve(root->right,maxAns);

        if(left < 0) left = 0;
        if(right < 0) right = 0;

        maxAns = max(root->val + left + right,maxAns);
        return root->val + max(left,right); //par cant atke both
    }

    int maxPathSum(TreeNode* root) {
        int maxAns = INT_MIN;
        solve(root,maxAns);
        return maxAns;
    }
};