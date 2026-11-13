class Solution {
public:
    void solve(vector<int> &nums , vector<int> &temp , vector<int> &used , vector<vector<int>>&ans){

        int n = nums.size();

        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0 ; i < n ; i++){

            if(used[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && used[i-1]) continue;


            used[i] = 1;
            temp.push_back(nums[i]);
            solve(nums,temp,used,ans);
            temp.pop_back();
            used[i] = 0;

        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> used(nums.size(),0);

        solve(nums,temp,used,ans);

        return ans;
        
    }
};