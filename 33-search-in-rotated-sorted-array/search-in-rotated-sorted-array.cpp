class Solution {
public:
    int search(vector<int>& nums, int target) {

        int s = 0 ,e = nums.size() - 1;

        while(e >= s){
            
            int mid = s + (e-s)/2;

            if(nums[mid] == target) return mid;

            else if(nums[mid] >= nums[0]){ //first line
                if(target >= nums[0] && target < nums[mid]) e = mid - 1;
                else s = mid + 1;
            }

            else{//second line
                if(target <= nums[nums.size() - 1] &&  target > nums[mid]) s = mid + 1;
                else e = mid - 1;
            }
        }

        return -1;
        
    }
};