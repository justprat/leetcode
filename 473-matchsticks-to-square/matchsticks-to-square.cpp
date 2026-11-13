class Solution {
public:
    int need = 0;

    bool solve(vector<int>& matchsticks , int remaining, vector<int>&used, int groupsTaken ,int sum,int j){

        int n = matchsticks.size();

        if(groupsTaken == 4){
            return (remaining == 0);
        }

        for(int i = j ; i < n ; i++){

            if(used[i]) continue;
            if(sum + matchsticks[i] > need) break;
            if(i > j && matchsticks[i] == matchsticks[i-1] && used[i-1]) continue;
            //take
            used[i] = 1;
            if(sum + matchsticks[i] == need){
                if(solve(matchsticks,remaining - 1,used,groupsTaken+1,0,0)) return true;
            }
            else{
                if(solve(matchsticks,remaining - 1,used,groupsTaken,sum + matchsticks[i],i + 1)) return true;
            }
            used[i] = 0;
    
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        sort(matchsticks.begin(),matchsticks.end());
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);

        need = sum / 4;
        if(need * 4 != sum || matchsticks.size() < 4) return false;

        vector<int> used(matchsticks.size(),0);

        int remaining = matchsticks.size();
        return solve(matchsticks,remaining,used,0,0,0);
        
    }
};