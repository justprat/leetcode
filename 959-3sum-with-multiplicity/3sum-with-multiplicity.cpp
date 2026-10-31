class Solution {
public:
    int threeSumMulti(vector<int>&nums, int target) {

        sort(nums.begin(),nums.end());

        int n = nums.size();

        int MOD = 1e9 + 7;
        long long res = 0;

        for(int i = 0 ; i < n - 2; i++){
            
            int left = i + 1;
            int right = n - 1;

            int need = target - nums[i];

            while(left < right){
                
                if(need < nums[left] + nums[right]){
                    right--;
                }

                else if(need > nums[left] + nums[right]){
                    left++;
                }

                else{

                    if(nums[left] == nums[right]){

                        int t = (right - left + 1);
                        res = (res + ((1LL * t * (t-1)) / 2) % MOD) % MOD;
                        break;

                    }

                    else{

                        int lv = nums[left];
                        int rv = nums[right];

                        int leftCount = 0;
                        int rightCount = 0;

                        while(left <= right && nums[left] == lv) {
                            leftCount++;
                            left++;
                        }

                        while(right >= left && nums[right] == rv) {
                            rightCount++;
                            right--;
                        }

                        // leftC1 * rightC1
                        res = (res + (1LL * leftCount * rightCount) % MOD) % MOD;
                    }   
                }
            }
        }

        return res;

    }
};