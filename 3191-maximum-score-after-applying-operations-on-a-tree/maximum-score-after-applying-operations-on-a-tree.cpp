class Solution {
public:
    //pair<bestSum,worstRemoval>
    pair<long long,long long> solve(int node , vector<vector<int>>&adj , vector<int>&values,int prev){

        int neiCount = 0;

        long long ans = values[node];
        long long worstRemoval = 0;

        for(auto nei : adj[node]){
            if(nei == prev) continue;

            pair<long long , long long> curr = solve(nei,adj,values,node);
            ans += curr.first;
            worstRemoval += curr.second;
            neiCount++;
        }

        if(neiCount == 0){
            return {values[node],values[node]};
        }

        if(worstRemoval > values[node] ){ // this node is best to keep
            return {ans,values[node]};
        }
        
        //remove large current , keep cheap children
        return {ans,worstRemoval};
        
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {

        int n = values.size();
        vector<vector<int>> adj(n);

        //1. create tree
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // 2. solve
        pair<long long,long long> ans = solve(0,adj,values,-1);
        return ans.first - ans.second;
        
    }
};