class Solution {
public:
    int solve(vector<int>&nums , vector<int>&used,int prev,int remaining){

        int n = nums.size();

        if(remaining == 0){
            return 1;
        }

        int count = 0;

        for(int i = 0 ; i < n ; i++){

            if(used[i]){
                continue;
            }

            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }

            if(prev == -1){
                used[i]++;
                count += solve(nums,used,nums[i],remaining-1);
                used[i]--;
            }
            else{
                int checkSquare = prev + nums[i];
                int root = sqrt(checkSquare);

                if(((long long) root * root) == checkSquare){//valid square
                    used[i]++;
                    count += solve(nums,used,nums[i],remaining-1);
                    used[i]--;
                }

                //naturally continue
            }
        }

        return count;

    }

    int numSquarefulPerms(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int n = nums.size();
        
        vector<int> used(n,0);

        return solve(nums,used,-1,n);
        
    }
};