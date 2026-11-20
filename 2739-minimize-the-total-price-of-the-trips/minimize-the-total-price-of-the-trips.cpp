class Solution {
public:
    bool dfs(int curr, int target , vector<vector<int>>&adj , vector<int>& timesSeen , int prev){

        if(curr == target){
            timesSeen[target]++;
            return true;
        }

        for(auto nei : adj[curr]){

            if(nei == prev) continue;

            if(dfs(nei,target,adj,timesSeen,curr)){//if we can reach closer , add this as seen
                timesSeen[curr]++;
                return true;
            }
        }

        return false;
    }

    pair<int,int> solve(int root , vector<vector<int>>&adj , vector<int> &price , int prev){

        vector<pair<int,int>> childValues;
        for(auto nei : adj[root]){

            if(nei == prev) continue;

            pair<int,int> childVal = solve(nei,adj,price,root);
            childValues.push_back(childVal);

        }

        //optimal take(curr->val/2 + skip all)
        int take = (price[root] / 2);
        for(int i = 0 ; i < childValues.size() ; i++){
            take += childValues[i].second;
        }

        //optimal skip -> pairwise max's
        int skip = 0;
        for(int i = 0 ; i < childValues.size() ; i++){
            skip += max(childValues[i].first,childValues[i].second);
        }

        return {take,skip};

    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {

        vector<int> timesSeen(n,0); // node seen

        //1. build adj list
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);     
        }

        //2. literally traverse and count occurences of node
        for(int i = 0 ; i < trips.size() ; i++){
            int u = trips[i][0];
            int v = trips[i][1];
            dfs(u,v,adj,timesSeen,-1);
        }

        //3. weightedCost = timesSeen * node_cost
        for(int i = 0 ; i < n ; i++){
            price[i] = price[i] * timesSeen[i];
        }

        //4. run house - robber on new weights
        pair<int,int> res = solve(0,adj,price,-1);//treat root as 0
        int maxRemoval = max(res.first,res.second);
        int totalSum = accumulate(price.begin(),price.end(),0);

        return totalSum - maxRemoval;
        
    }
};