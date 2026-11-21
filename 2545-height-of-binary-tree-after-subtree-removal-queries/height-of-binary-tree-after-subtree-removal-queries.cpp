class Solution {
public:
    int height[100005][2];
    int depth[100005];
    int nodeH[100005];

    int dfs(int d, TreeNode* root){

        if (root == NULL) return -1;

        int left = dfs(d + 1, root->left);
        int right = dfs(d + 1, root->right);
        int h = max(left, right) + 1;

        depth[root->val] = d;
        nodeH[root->val] = h;

        if (h >= height[d][0]){
            height[d][1] = height[d][0];
            height[d][0] = h;
        }
        else if(h > height[d][1]){
            height[d][1] = h;
        }

        return h;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        memset(height, -1, sizeof(height));
        dfs(0, root);

        vector<int> ans;

        for (int node : queries) {

            int d = depth[node];

            if (nodeH[node] == height[d][0]) {
                ans.push_back(d + height[d][1]);
            }
            else{
                ans.push_back(d + height[d][0]);
            }
        }

        return ans;
    }
};