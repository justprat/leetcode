class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();

        int currSum = 0;
        int minSize = n + 1;

        int l = 0;

        for(int r = 0 ; r < n ; r++){

            currSum += nums[r];

            while(currSum >= target){
                minSize = min(minSize,r - l + 1);
                currSum -= nums[l];
                l++;
            }
        }

        return (minSize == n + 1) ? 0 : minSize;
    }
};