class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;

        while(e>s){

            int mid= s +(e-s)/2;

            if(nums[mid]==nums[e] && nums[mid] == nums[s]){  // if all equal , you will losemonotonic //never ever move randomly
                s++;
                e--;
            }

            else if(nums[mid]>nums[e]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return nums[s];
    }
};