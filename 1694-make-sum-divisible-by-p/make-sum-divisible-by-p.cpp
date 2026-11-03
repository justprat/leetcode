class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int n = nums.size();

        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }

        if(sum % p == 0) return 0;
        long long need = sum % p;
        unordered_map<int,int> mp;
        mp[0] = -1;

        long long preSum = 0;
        int shortest = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            preSum = (preSum + nums[i]) % p;
            long long target = (preSum - need + p) % p;
            if(mp.count(target)) shortest = min(shortest,i - mp[target]);
            mp[preSum] = i;
        }

        return (shortest == INT_MAX || shortest == n) ? -1 : shortest; 
        
    }
};