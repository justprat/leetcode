class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int MOD = 1e9 + 7;

        vector<int> pow2(n);
        pow2[0] = 1;

        //1. precompute powers cos 1 << gap wont work
        for (int i = 1; i < n; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % MOD;
        }

        int count = 0;
        int l = 0, r = n - 1;

        while (l <= r) {

            if(nums[l] + nums[r] <= target){//think [L....R] gap with any one anchored
                count = (count + 1LL * pow2[r-l]) % MOD;
                l++;
            } 
            else{
                r--;
            }
        }

        return count;

    }
};