class Solution {
public:
    int solve(int left , string &s , int k , vector<vector<int>> &pal, vector<int> &dp){

        int n = s.size();

        if(left >= n){
            return 0;
        }

        if(dp[left] != -1){
            return dp[left];
        }

        int res = solve(left+1,s,k,pal,dp); //skip

        for(int right = left ; right < n ; right++){//try to take

            if(pal[left][right] && (right - left + 1 >= k)){
                res = max(res,1 + solve(right+1,s,k,pal,dp));
            }

        }

        return dp[left] = res;

    }

    int maxPalindromes(string s, int k) {

        int n = s.size();
        vector<vector<int>> pal(n,vector<int>(n,0));

        for(int i = 0 ; i < n ; i++){
            pal[i][i] = 1;
        }

        for(int len = 2 ; len <= n ; len++){
            for(int l = 0 ; len + l - 1 < n ; l++){

                int r = len + l - 1;

                if(len == 2){
                    if(s[l] == s[r]) pal[l][r] = 1;
                }

                else{
                    if(pal[l+1][r-1] && s[l] == s[r]){
                        pal[l][r] = 1;
                    }
                }
            }
        }

        vector<int> dp(n,-1);

        return solve(0,s,k,pal,dp);
        
    }
};