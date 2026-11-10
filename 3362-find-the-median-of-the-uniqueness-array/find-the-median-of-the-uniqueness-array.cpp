class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {

        int n = nums.size();

        long long k = 1LL * n * (n + 1) / 2;

        int s = 1 , e = n;
        int ans = -1;

        while(e >= s){
            
            int mid = s + (e - s)/ 2;

            //count subarrays with unique elements <= mid
            int l = 0;
            long long count = 0;

            unordered_map<int,int> mp;

            for(int r = 0 ; r < n ; r++){

                mp[nums[r]]++;

                while(mp.size() > mid){
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) mp.erase(nums[l]);
                    l++;
                }

                count += r - l + 1;

            }

            //did we overshoot?
            if(count >= ((k + 1)/ 2)){
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