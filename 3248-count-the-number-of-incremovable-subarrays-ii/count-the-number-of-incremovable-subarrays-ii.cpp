class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {

        int n = nums.size();

        long long count = 1;

        //1. extract [suffix .... n -1]
        int suffix = n - 1;
        while(suffix > 0 && nums[suffix - 1] < nums[suffix]){
            suffix--;
        }
        
        if(suffix == 0){
            return ((long long)n * (n + 1))/2;
        }

        //2. extract[0 .... prefix]
        int prefix = 0;
        while(prefix < n - 1 && nums[prefix] < nums[prefix + 1]){
            prefix++;
        }

        //3. count => remove all suffix , and all prefix
        count += (prefix + 1);
        count += ((n - 1) - suffix + 1);

        //4. 2 pointers
        int i = 0;
        int j = suffix;
        while(i <= prefix && j < n){

            if(nums[i] < nums[j]){
                count += (n - j); // (n - 1 - j + 1)
                i++;
            }
            else{
                j++;
            }
        }

        return count;
        
    }
};