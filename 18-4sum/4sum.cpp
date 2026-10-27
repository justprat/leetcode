class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i = 0 ; i < n - 3 ; i++){

            //handle dup
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j = i + 1 ; j < n - 2 ; j++){

                //handle dup
                if(j > i + 1 && nums[j] == nums[j-1]){
                    continue;
                }

                int l = j + 1;
                int r = n - 1;

                long long need = (long long) target - nums[i] - nums[j];

                while(l < r){

                    if((long long) need - nums[l] - nums[r] > 0){
                        l++;
                    }

                    else if((long long) need - nums[l] - nums[r] < 0){
                        r--;
                    }

                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;

                        while(l < n && nums[l-1] == nums[l]){
                            l++;
                        }

                        while(r > j && nums[r] == nums[r+1]){
                            r--;
                        }
                    }
                }
            }
        }

        return ans;

    }
};