class Solution {
public:

    bool solve(int i , vector<int>&ans, vector<int>&used , int remaining){

        int n = used.size() - 1;
        int m = 2 * n - 1;

        if(remaining == 0){
            return true;
        }

        if(ans[i] != -1){
            return solve(i+1,ans,used,remaining);
        }

        for(int vals = n ; vals >= 1 ; vals--){

            if(used[vals]) continue;

            if(vals == 1){

                ans[i] = vals;
                used[vals]++;

                if(solve(i+1,ans,used,remaining-1)) return true;

                used[vals]--;
                ans[i] = -1;
            }

            else if(ans[i] == -1 && (i + vals < m && ans[i + vals] == -1)){

                ans[i] = vals;
                ans[i+vals] = vals;
                used[vals]++;

                if(solve(i+1,ans,used,remaining-1)) return true;

                used[vals]--;
                ans[i+vals] = -1;
                ans[i] = -1;
            }
        }

        return false;

    }
    vector<int> constructDistancedSequence(int n) {

        vector<int> ans(2 * n - 1,-1);

        vector<int>used(n+1,0);
        int remaining = n;

        solve(0,ans,used,remaining);
        return ans;
    }
};