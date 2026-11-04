class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {

        int n = nums.size();

        //1. transform nums
        for(int i = 0 ; i < n ; i++){
           if(nums[i] % modulo == k){
                nums[i] = 1;//contribute
           }
           else{
                nums[i] = 0; //doesnt
           }
        }

        //2. store prevCounts
        unordered_map<int,long long> mp;
        mp[0] = 1;

        int currSum = 0;
        long long count = 0;

        for(int i = 0 ; i < n ; i++){

            currSum += nums[i];
            
            //(B - A) % M = K
            // BmodM - AmodM = K
            // AmodM = BmodM - K
            // AmodM = (((BmodM - K )% M) + M) % M
            long long target = (((currSum % modulo - k) % modulo) + modulo) % modulo;
            count+= mp[target];

            mp[currSum % modulo]++;

        }

        return count;
        
    }
};