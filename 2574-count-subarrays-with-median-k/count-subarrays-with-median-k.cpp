class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        //step 1: transform
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > k){
                nums[i] = 1;
            }
            else if(nums[i] < k){
                nums[i] = -1;
            }
            else{
                nums[i] = 0;
            }
        }

        //step 2: count carefully
        unordered_map<int,int> mp;
        mp[0] = 1;

        int Kindex = -1;
        int balance = 0;
        long long count = 0;

        for(int right = 0 ; right < n ; right++){

            if(nums[right] == 0){
                Kindex = right;
            }

            if(Kindex == -1){
                balance += nums[right];
                mp[balance]++;
                continue;
            }

            //K has been reached , we count
            balance += nums[right];

            count += mp[balance];
            count += mp[balance - 1];

        }

        return count;
        
    }
};