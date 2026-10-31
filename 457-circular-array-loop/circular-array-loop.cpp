class Solution {
public:
    int getNext(int slow ,vector<int> &nums){

        int n = nums.size();

        int nextIdx = (slow + nums[slow] % n + n) % n;

        if(nums[slow] == 0 || nextIdx == slow) return -1e7;

        return nextIdx;
        
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0 ; i <  n ; i++){

            if(nums[i] != 0){

                int slow = i;
                int fast = i;

                bool isForward = (nums[i] > 0);
                bool valid = true;

                do{
                    slow = getNext(slow,nums);
                    if(slow == - 1e7 || (nums[slow] > 0) != isForward){
                        valid = false;
                        break;
                    }

                    fast = getNext(fast, nums);
                    if (fast == -1e7 || (nums[fast] > 0) != isForward) { valid = false; break; }

                    fast = getNext(fast, nums);
                    if (fast == -1e7 || (nums[fast] > 0) != isForward) { valid = false; break; }

                } while(slow != fast);

                if(valid){
                    return true;
                }

                slow = i;
                while(slow > 0){
                    nums[slow] = 0;
                    slow = getNext(slow,nums);
                }

            }
        }

        return false;
        
    }
};