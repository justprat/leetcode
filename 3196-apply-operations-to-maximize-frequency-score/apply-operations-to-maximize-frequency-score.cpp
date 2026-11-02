class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {

        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<long long> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int left = 0;
        int maxAns = 0;

        for(int right = 0 ; right < n ; right++){
            
            long long t = (left == 0) ? 0 : prefix[left - 1];
            long long mid = (right + left) /2;

            long long leftCost = (1LL * (mid - left + 1) * nums[mid] -  (prefix[mid] - t)) ;
            long long rightCost = (1LL * (prefix[right] - prefix[mid]) - (right - mid) * nums[mid]);
            long long steps = leftCost + rightCost;

            while(steps > k){

                left++;
                mid = (right + left) /2;

                leftCost = (1LL * (mid - left + 1) * nums[mid] - (prefix[mid] - prefix[left - 1]));
                rightCost = (1LL * (prefix[right] - prefix[mid]) - (right - mid) * nums[mid]);
                steps = leftCost + rightCost;
            }

            maxAns = max(maxAns,right - left + 1);

        }

        return maxAns;
        
    }
};