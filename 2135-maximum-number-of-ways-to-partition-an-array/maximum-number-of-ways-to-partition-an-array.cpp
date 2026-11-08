class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {

        int n = nums.size();

        //1. sum
        long long total = 0;
        for(int i = 0 ; i < n ; i++){
            total += nums[i];
        }

        unordered_map<long long , int> ahead;
        unordered_map<long long , int> behind;
        
        //2. precompute future
        long long left = 0;
        for(int i = 0 ; i < n - 1; i++){
            left += nums[i];
            long long right = total - left;
            
            long long gap = left - right;
            ahead[gap]++;
        }

        int maxAns = ahead[0];
        //3. try replace each index by k and tracking behind also
        left = 0;
        for(int i = 0 ; i < n ; i++){

            long long right = total - left;
            long long change = k - nums[i];

            //this index fixed left and right issues
            int pastFixed = behind[change];
            int futureFixed =  ahead[-change];

            maxAns = max(maxAns, pastFixed + futureFixed);

            if(i < n - 1){
                left += nums[i];
                right = total - left;
                long long gap = left - right;

                //move window ahead
                ahead[gap]--;
                behind[gap]++;
            }
        }

        return maxAns;
        
    }
};