class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int s = 0;
        int e = nums[nums.size() - 1] - nums[0];

        int ans = -1;

        while(e >= s){

            int mid = s + (e-s)/2;

            int l = 0;
            int count = 0;

            for(int r = 0 ; r < nums.size() ; r++){

                while(nums[r] - nums[l] > mid){
                    l++;
                }

                count += r - l;

            }

            if(count >= k){
                ans = mid;
                e = mid - 1;
            }

            else{
                s = mid + 1;
            }
        }

        return ans;
        
    }
};