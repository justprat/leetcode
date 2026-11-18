class Solution {
public:
    int DISTANCE;
    pair<int,int> findRootDistances(int node , vector<vector<int>> &adj,int par,vector<int>&nodes){

        int sum = 0;
        int count = 1;
        for(auto nei : adj[node]){

            if(nei == par) continue;

            pair<int,int> res = findRootDistances(nei,adj,node,nodes);
            sum = sum + res.first + res.second;
            count += res.second;
        }
        nodes[node] = count;
        return {sum,count};
    }

    void solve(int node , vector<vector<int>> &adj , vector<int>&ans ,vector<int>&nodes, int par){

        int n = ans.size();

        if(node == 0){
            ans[node] = DISTANCE;
            
            for(auto nei : adj[node]){
                solve(nei,adj,ans,nodes,node);
            }
        }
        else{
            ans[node] = ans[par] - nodes[node] + (n - nodes[node]);

            for(auto nei : adj[node]){
                if(nei == par) continue;
                solve(nei,adj,ans,nodes,node);
            }
        }

    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> nodes(n,0);

        DISTANCE = findRootDistances(0,adj,-1,nodes).first;

        vector<int> ans(n,0);
        solve(0,adj,ans,nodes,-1);
        return ans;
        
    }
};