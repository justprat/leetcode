class Solution {
public:
    int atMost(vector<int>& nums, int k){

        int n = nums.size();
        if(k == 0) return 0;

        int l = 0;
        int count = 0;
        unordered_map<int,int> mp;

        for(int r = 0 ; r < n ; r++){

            mp[nums[r]]++;

            while(mp.size() > k){
                
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }

                l++;
            }

            count += r - l + 1;

        }

        return count;

    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k - 1);
    }
};